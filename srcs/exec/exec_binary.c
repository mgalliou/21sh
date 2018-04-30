/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_binary.cmd                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 17:08:36 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/14 21:06:15 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>

static int		fork_and_exec(char *path, char **cmdav)
{
	extern char	**environ;
	int			status;
	int			child_pid;

	child_pid = -1;
	status = -1;
	if (g_pid != -2)
		g_pid = fork();
	if (g_pid > 0)
	{
		child_pid = waitpid(g_pid, &status, WUNTRACED);
	}
	if (!g_pid || g_pid == -2)
	{
		if (-1 == execve(path, cmdav, environ))
			kill(g_pid, SIGINT);
	}
	g_pid = -1;
	return (handle_exitstatus(cmdav[0], child_pid, status));
}

static int		handle_error(char *path, char *name)
{
	struct stat pathstat;

	if (!path)
	{
		ft_printf("%w%s: %s: %s\n", 2, SHELLNAME, EMNOCMD, name);
		return (127);
	}
	if (!stat(path, &pathstat) && S_ISDIR(pathstat.st_mode))
	{
		ft_printf("%w%s: %s: %s\n", 2, SHELLNAME, EMISDIR, name);
		return (126);
	}
	if (-1 == access(path, F_OK))
	{
		ft_printf("%w%s: %s: %s\n", 2, SHELLNAME, EMNOENT, path);
		return (1);
	}
	else if (-1 == access(path, X_OK))
	{
		ft_printf("%w%s: %s: %s\n", 2, SHELLNAME, EMACCES, name);
		return (126);
	}
	return (0);
}

char			*get_binpath(char *name, t_rb_node *binaries)
{
	int			diff;

	if (binaries)
	{
		diff = ft_strcmp(((t_bin*)binaries->item)->name, name);
		if (!diff)
			return (((t_bin*)binaries->item)->path);
		else if (diff > 0)
			return (get_binpath(name, binaries->left));
		else if (diff < 0)
			return (get_binpath(name, binaries->right));
	}
	return (NULL);
}

int				exec_binary(char **cmdav, t_rb_node *binaries)
{
	char		*path;
	int			exitcode;

	if (!cmdav || !cmdav[0])
		return (0);
	if (cmdav[0][0] == '/' || ft_strnequ(cmdav[0], "./", 2) ||
			ft_strnequ(cmdav[0], "../", 3) || !binaries)
		path = cmdav[0];
	else
		path = get_binpath(cmdav[0], binaries);
	if (!(exitcode = handle_error(path, cmdav[0])))
		exitcode = fork_and_exec(path, cmdav);
	return (exitcode);
}
