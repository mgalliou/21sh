/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pathcmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 18:46:36 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/18 21:02:50 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>
#include <dirent.h>

static int			bincmp(void *bin1, void *bin2)
{
	return (ft_strcmp(((t_bin*)bin1)->name, ((t_bin*)bin2)->name));
}

static t_bin		*binnew(char *dir, char *name)
{
	t_bin			*bin;

	if ((bin = ft_memalloc(sizeof(t_bin))))
	{
		if (!(bin->path = ft_strcjoin(dir, name, '/')))
			ft_memdel((void*)bin);
		else
			bin->name = &(bin->path[ft_strlen(dir) + 1]);
	}
	return (bin);
}

t_rb_node			*get_binaries(char *envpath)
{
	t_rb_node		*binaries;
	char			**path;
	DIR				*dirp;
	struct dirent	*entry;
	int				i;

	if (!envpath || !(path = ft_strsplit(envpath, ':')))
		return (NULL);
	binaries = NULL;
	i = -1;
	while (path[++i])
	{
		if ((dirp = opendir(path[i])))
		{
			while ((entry = readdir(dirp)))
				if (!ft_strequ(entry->d_name, ".") &&
						!ft_strequ(entry->d_name, ".."))
					rb_insert(&binaries, binnew(path[i], entry->d_name),
							&bincmp);
			closedir(dirp);
		}
	}
	ft_tabdel(&path);
	return (binaries);
}
