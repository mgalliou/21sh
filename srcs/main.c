/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 11:47:42 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/22 17:39:29 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

int					main(int ac, char **av)
{
	static t_shell	*shell = NULL;
	char			*cmdline;
	int				ret;

	if (!(shell = shell_init(ac, av)))
		return (1);
	ret = 1;
	while (ret == 1)
	{
		ret = get_cmdline("$> ", &cmdline, shell);
		if (ret == 1)
			shell->exitcode = cmdline_interpret(cmdline, shell);
	}
	default_terminal_mode();
	return (shell->exitcode);
}
