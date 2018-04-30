/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 15:09:17 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/14 20:57:36 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

static int	bi_history(char **cmd, t_shell *shell)
{
	(void)cmd;
	ft_puttab(shell->history);
	return (0);
}

int			exec_builtin(char **cmdav, t_shell *shell)
{
	if (!cmdav || !cmdav[0])
		return (shell->exitcode);
	if (ft_strequ(cmdav[0], "echo"))
		return (bi_echo(cmdav));
	else if (ft_strequ(cmdav[0], "cd"))
		return (bi_cd(cmdav));
	else if (ft_strequ(cmdav[0], "setenv"))
		return (bi_setenv(cmdav));
	else if (ft_strequ(cmdav[0], "unsetenv"))
		return (bi_unsetenv(cmdav));
	else if (ft_strequ(cmdav[0], "env"))
		return (bi_env(cmdav));
	else if (ft_strequ(cmdav[0], "exit"))
		return (bi_exit(cmdav, shell->exitcode));
	else if (ft_strequ(cmdav[0], "plec"))
		return (bi_plec(cmdav, shell->exitcode));
	else if (ft_strequ(cmdav[0], "history"))
		return (bi_history(cmdav, shell));
	return (-1);
}
