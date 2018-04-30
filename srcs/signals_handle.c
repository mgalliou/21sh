/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:09:50 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/18 20:26:25 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>
#include <signal.h>

static void		handle_sigint(int sig)
{
	if (g_pid > 0)
	{
		ft_putchar_fd('\n', 2);
		kill(g_pid, sig);
	}
}

static void		handle_sigpipe(int sig)
{
	if (g_pid <= 0 && g_pid != -1)
		exit(sig);
}

void			signals_handle(void)
{
	int	signb;

	signb = 31;
	while (signb > 0)
	{
		if (signb == SIGINT)
			signal(signb, &handle_sigint);
		else if (signb == SIGPIPE)
			signal(signb, &handle_sigpipe);
		else if (signb == SIGHUP || signb == SIGQUIT || signb == SIGKILL
				|| signb == SIGALRM || signb == SIGTERM)
			signal(signb, SIG_IGN);
		else
			signal(signb, SIG_DFL);
		signb--;
	}
}
