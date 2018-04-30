/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 10:14:58 by mgalliou          #+#    #+#             */
/*   Updated: 2017/09/29 12:47:27 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

int		bi_unsetenv(char **av)
{
	int	i;

	i = 1;
	if (!av[i])
	{
		ft_printf("%w%s: %s\n", 2, av[0], EMTOFEWARG);
		return (1);
	}
	while (!ft_unsetenv(av[i++]))
		;
	return (0);
}
