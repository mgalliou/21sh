/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 14:23:48 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/13 20:27:04 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

int	bi_exit(char **av, int exitcode)
{
	int	i;

	if (av[1])
	{
		i = -1;
		while (ft_isdigit(av[1][++i]))
			;
		if (av[1][i] && !ft_isdigit(av[1][i]))
		{
			ft_printf("%w%s: %s: %s: %s\n",
					2, SHELLNAME, av[0], av[1], EMNONUMARG);
			exit(255);
		}
		else if (av[2])
		{
			ft_printf("%w%s: %s: %s\n", 2, SHELLNAME, av[0], EMTOMNYARG);
			return ((exitcode = 1));
		}
		else
			exitcode = ft_atoi(av[1]);
	}
	exit(exitcode % 256);
}
