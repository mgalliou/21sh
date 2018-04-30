/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 10:14:16 by mgalliou          #+#    #+#             */
/*   Updated: 2018/02/16 11:48:10 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>
#include <stdlib.h>

static int		isvalidename(char *name)
{
	int			i;

	i = 0;
	while (name[i])
	{
		if (!i && ft_isdigit(name[i]))
		{
			ft_printf("%w%s: %s.\n", 2, name, EMVNMGWL);
			return (0);
		}
		if (!ft_isalnum(name[i]) && name[i] != '_')
		{
			ft_printf("%w%s: %s.\n", 2, name, EMWRGVAR);
			return (0);
		}
		i++;
	}
	return (1);
}

int				bi_setenv(char **av)
{
	extern char **environ;

	if (!av[1])
		ft_puttab(environ);
	else if (isvalidename(av[1]))
	{
		if (av[2] && av[3])
		{
			ft_printf("%w%s: %s.\n", 2, av[0], EMTOMNYARG);
			return (1);
		}
		else if (-1 == ft_setenv(av[1], av[2], 1))
			return (1);
		return (0);
	}
	return (1);
}
