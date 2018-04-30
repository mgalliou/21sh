/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envpathentry.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:14:17 by mgalliou          #+#    #+#             */
/*   Updated: 2017/09/07 16:35:10 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <dirent.h>

char			*get_envpathentry(char *cmd, char *envivar)
{
	char			**path;
	char			*pathentry;
	DIR				*dirp;
	struct dirent	*entry;
	int				i;

	if (!(path = ft_strsplit(ft_getenv(envivar), ':')))
		return (NULL);
	pathentry = NULL;
	i = -1;
	while (!pathentry && path[++i])
	{
		if ((dirp = opendir(path[i])))
		{
			while (!pathentry && (entry = readdir(dirp)))
				if (ft_strequ(cmd, entry->d_name))
					pathentry = ft_strcjoin(path[i], cmd, '/');
			closedir(dirp);
		}
	}
	ft_tabdel(&path);
	return (pathentry);
}
