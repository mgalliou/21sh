/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 10:12:23 by mgalliou          #+#    #+#             */
/*   Updated: 2017/10/13 14:55:17 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

int			bi_echo(char **av)
{
	int		i;
	int		ret;
	char	c[2];

	i = 1;
	if (av[i])
	{
		c[0] = '\n';
		if (ft_strequ(av[i], "-n"))
		{
			c[0] = '\0';
			++i;
		}
		c[1] = '\0';
		while (av[i])
		{
			ret = ft_printf("%s%s", av[i], (av[i + 1] ? " " : c));
			++i;
		}
	}
	else
		ret = ft_printf("\n");
	return (ret >= 0 ? 0 : 1);
}
