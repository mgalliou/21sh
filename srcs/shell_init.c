/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:11:04 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/25 16:30:05 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>
#include <termios.h>
#include <unistd.h>
#include <signal.h>

static void			init_environ(void)
{
	char			*shlvlc;
	int				shlvln;

	if ((shlvlc = ft_getenv("SHLVL")))
		shlvln = ft_atoi(shlvlc) + 1;
	else
		shlvln = 1;
	ft_setenv("SHLVL", (shlvlc = ft_itoa(shlvln)), 1);
	ft_setenv("CLICOLOR", "1", 1);
	ft_strdel(&shlvlc);
}

static void			init_variables(t_shell *shell, int ac, char **av)
{
	static char		*builtins[] = {"echo", "cd", "setenv", "unsetenv",
									"env", "exit", "plec", "history", NULL};

	shell->ac = ac;
	shell->av = av;
	if ((shell->isinteractive = isatty(STDIN_FILENO)))
		tcgetattr(STDIN_FILENO, &(shell->old_tattr));
	shell->builtins = builtins;
	shell->envpath = NULL;
	shell->binaries = NULL;
	shell->exitcode = 0;
	shell->lastcmdline = NULL;
}

static void			init_history(t_shell *shell)
{
	shell->history = NULL;
	if (MAX_HISTORY_LEN > 0)
		shell->history = ft_memalloc(sizeof(char*) * (MAX_HISTORY_LEN + 1));
	shell->historylen = 0;
}

t_shell				*shell_init(int ac, char **av)
{
	static t_shell	*shell = NULL;

	if (!shell)
		shell = ft_memalloc(sizeof(t_shell));
	if (shell)
	{
		g_pid = -1;
		signals_handle();
		init_environ();
		init_variables(shell, ac, av);
		init_history(shell);
		shell = shell_update(NULL, shell);
	}
	return (shell);
}
