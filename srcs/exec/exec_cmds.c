/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:59:08 by edhommee          #+#    #+#             */
/*   Updated: 2018/04/21 20:17:47 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <unistd.h>
#include <sys/wait.h>

static int		exec_cmd(t_cmd *cmd, t_shell *shell)
{
	if (apply_redir(cmd->redir) == 0)
	{
		if ((-1 == (shell->exitcode = exec_builtin(cmd->av, shell))))
			shell->exitcode = exec_binary(cmd->av, shell->binaries);
	}
	else
		shell->exitcode = 1;
	reverse_redir(cmd->redir);
	return (shell->exitcode);
}

static int		fork_fd(int p)
{
	static int	fd = -1;
	int			tmp[2];

	if (p)
		pipe(tmp);
	g_pid = fork();
	if (g_pid <= 0)
	{
		g_pid = -2;
		if (fd >= 0)
			dup2(fd, 1);
		if (p && close(tmp[1]) == 0)
			dup2(tmp[0], 0);
	}
	else
	{
		if (fd >= 0)
			close(fd);
		fd = (p) ? tmp[1] : -1;
		if (p)
			close(tmp[0]);
	}
	return (g_pid);
}

static int		exec_one(t_cmd *cmd, t_cmd *next, t_shell *shell)
{
	int			child;

	child = 0;
	if ((next && next->sep == PIPE) || cmd->sep == PIPE)
	{
		if (cmd->sep == PIPE)
			child = fork_fd(1);
		else
			child = fork_fd(0);
		if (child == -2)
		{
			shell->exitcode = exec_cmd(cmd, shell);
			exit(shell->exitcode);
		}
		g_pid = -1;
	}
	else
		shell->exitcode = exec_cmd(cmd, shell);
	return (child);
}

static t_list	*exec_each(t_list *cmd, t_shell *shell, int *pid)
{
	t_list		*last;

	if (!cmd)
		return (NULL);
	if (cmd->next && ((t_cmd*)cmd->next->content)->sep == PIPE)
	{
		last = exec_each(cmd->next, shell, pid);
		exec_one(cmd->content, cmd->next->content, shell);
	}
	else
	{
		last = cmd;
		*pid = exec_one(cmd->content, NULL, shell);
	}
	return (last);
}

int				exec_cmds(t_list *cmds, t_shell *shell)
{
	int			status;
	int			child_pid;

	if (!cmds)
		return (-1);
	while ((cmds = exec_each(cmds, shell, &child_pid)))
	{
		if (child_pid)
		{
			if ((child_pid = waitpid(child_pid, &status, WUNTRACED)))
				shell->exitcode = handle_exitstatus(NULL, child_pid, status);
		}
		while ((child_pid = waitpid(0, &status, WUNTRACED) != -1))
			;
		cmds = cmds->next;
	}
	return (0);
}
