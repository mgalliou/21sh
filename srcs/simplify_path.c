/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 16:36:04 by mgalliou          #+#    #+#             */
/*   Updated: 2017/10/17 15:03:12 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <shell.h>

static int	goto_lastcomp(char *path, int i)
{
	int		start;

	start = i;
	while (i && --i && path[i] == '/')
		;
	if (!i && path[i] == '/')
		return (start);
	while (i && path[i - 1] != '/')
		i--;
	if (isdotdot(&path[i]))
		return (start);
	return (i);
}

char		*simplify_path(char *path)
{
	int		i;
	int		j;

	i = 0;
	if (!path)
		return (path);
	while (path[j = i])
	{
		if ((path[i] == '.' && (path[i + 1] == '/' || !path[i + 1])) ||
				(i && path[i] == '/' && path[i - 1] == '/'))
			++j;
		else if ((!i || path[i - 1] == '/') && isdotdot(&path[i]) && (j += 2))
			i = goto_lastcomp(path, i);
		while ((j > i && path[j] == '/'))
			++j;
		if (j > i)
			ft_strcpy(&path[i], &path[j]);
		else
			++i;
	}
	while (--i && path[i] == '/')
		path[i] = '\0';
	return (path);
}
