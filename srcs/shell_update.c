/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:02:36 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/22 15:47:57 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static void		update_path(t_shell *shell)
{
	char		*envpath;

	envpath = ft_getenv("PATH");
	if ((envpath && !shell->envpath) ||
			(envpath && shell->envpath && !ft_strequ(shell->envpath, envpath)))
	{
		ft_strdel(&(shell->envpath));
		rb_delete(&(shell->binaries), &bindel);
		shell->envpath = ft_strdup(envpath);
		shell->binaries = get_binaries(shell->envpath);
	}
	else if (!envpath && shell->envpath)
	{
		ft_strdel(&shell->envpath);
		rb_delete(&(shell->binaries), &bindel);
		shell->binaries = NULL;
	}
}

static void		update_history(char *lastcmdline, t_shell *shell)
{
	int			i;

	shell->lastcmdline = lastcmdline;
	if (shell->history && shell->lastcmdline)
	{
		if (shell->historylen == MAX_HISTORY_LEN)
		{
			i = 0;
			ft_strdel(&shell->history[i]);
			while (i < shell->historylen)
			{
				shell->history[i] = shell->history[i + 1];
				++i;
			}
		}
		if (shell->historylen < MAX_HISTORY_LEN)
			++shell->historylen;
		shell->history[shell->historylen - 1] = shell->lastcmdline;
		shell->history[shell->historylen] = NULL;
	}
}

t_shell			*shell_update(char *lastcmdline, t_shell *shell)
{
	update_path(shell);
	update_history(lastcmdline, shell);
	return (shell);
}
