/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_exitstatus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:04:33 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/17 16:58:47 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>
#include <signal.h>

static void		print_signal(char *name, int pid, int exitcode)
{
	if (WTERMSIG(exitcode) == SIGABRT)
		ft_printf("%u abort %s\n", pid, name);
	else if (WTERMSIG(exitcode) == SIGBUS)
		ft_printf("%u bus error %s\n", pid, name);
	else if (WTERMSIG(exitcode) == SIGSEGV)
		ft_printf("%u segmentation fault %s\n", pid, name);
}

int				handle_exitstatus(char *cmd, int pid, int status)
{
	if (pid == -1 || status == -1)
		return (1);
	if (WIFSIGNALED(status))
	{
		print_signal(cmd, pid, status);
		return (WTERMSIG(status) + 128);
	}
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (0);
}
