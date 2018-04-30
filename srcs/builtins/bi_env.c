/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 16:20:41 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/17 20:07:00 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>
#include "../exec/exec.h"

static int		illegal_opt(char c)
{
	ft_printf("%wenv: illegal option -- %c\n", 2, c);
	ft_printf("%wusage: env [-i] [name=value ...] [utility [argument ...]]\n",
			2);
	return (-1);
}

/*
**	ft_printf("%wusage: env [-iv] [-P utilpath] [-S string]\n", 2);
**	ft_printf(
**			"%w         [-u name][name=value ...] [utility [argument ...]]\n",
**			2);
*/

static int		get_options(char **av, char *opts)
{
	int			i;
	int			j;

	i = 0;
	ft_bzero(opts, 128);
	while (av[++i] && ft_strcmp(av[i], "--") && (av[i][0] == '-' && av[i][1]))
	{
		j = 0;
		while (av[i][++j])
		{
			if (ft_strchr(ENV_OPTIONS, av[i][j]))
				opts[(int)av[i][j]] = av[i][j];
			else
				return (illegal_opt(av[i][j]));
		}
	}
	if (av[i] && ft_strequ(av[i], "--"))
		++i;
	return (i);
}

int				bi_env(char **av)
{
	extern char **environ;
	char		**envp;
	t_rb_node	*tmpbinaries;
	char		opts[128];
	int			i;

	if (-1 == (i = get_options(av, opts)))
		return (1);
	if (!(envp = environ) || opts['i'])
		environ = NULL;
	else if (!(environ = ft_tabdup(environ)))
		return (1);
	while (av[i] && ft_strchr(av[i], '='))
		ft_putenv(ft_strdup(av[i++]));
	if (!av[i] && !(i = 0))
		ft_puttab(environ);
	else
	{
		tmpbinaries = get_binaries(ft_getenv("PATH"));
		i = exec_binary(&av[i], tmpbinaries);
		rb_delete(&tmpbinaries, &bindel);
	}
	ft_tabdel(&environ);
	environ = envp;
	return (i);
}
