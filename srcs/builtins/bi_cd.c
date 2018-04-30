/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 10:13:43 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/23 15:07:54 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>
#include <unistd.h>
#include <sys/param.h>
#include <sys/stat.h>

static int		change_dir(char *curpath, char *dir, char opt)
{
	char	*cwd;

	if (!curpath)
		return (1);
	if (chdir(curpath))
		return (1);
	ft_setenv("OLDPWD", ft_getenv("PWD"), 1);
	if (opt == 'P')
	{
		ft_setenv("PWD", cwd = getcwd(NULL, 0), 1);
		ft_strdel(&cwd);
	}
	else
		ft_setenv("PWD", curpath, 1);
	if (dir && ft_strequ(dir, "-"))
		ft_printf("%s\n", ft_getenv("PWD"));
	return (0);
}

static char		*convert_curpath(char *curpath)
{
	char		*tmp;
	char		*cwd;

	cwd = NULL;
	if (curpath[0] != '/')
	{
		if (!(tmp = ft_getenv("PWD")))
		{
			cwd = getcwd(NULL, 0);
			tmp = cwd;
		}
		if (tmp && tmp[ft_strlen(tmp) - 1] == '/')
			tmp = ft_strjoin(tmp, curpath);
		else if (tmp)
			tmp = ft_strcjoin(tmp, curpath, '/');
		ft_strdel(&curpath);
		ft_strdel(&cwd);
		curpath = tmp;
	}
	curpath = simplify_path(curpath);
	return (curpath);
}

static int		handle_error(char *curpath)
{
	struct stat pathstat;

	if (!stat(curpath, &pathstat) && !S_ISDIR(pathstat.st_mode))
	{
		ft_printf("%wcd: %s: %s\n", 2, EMNOTDIR, curpath);
		return (1);
	}
	if (-1 == access(curpath, F_OK))
	{
		ft_printf("%wcd: %s: %s\n", 2, EMNOENT, curpath);
		return (1);
	}
	if (-1 == access(curpath, R_OK))
	{
		ft_printf("%wcd: %s: %s\n", 2, EMACCES, curpath);
		return (1);
	}
	return (0);
}

static char		*get_curpath(char *dir)
{
	char		*curpath;

	if (!dir && !(dir = ft_getenv("HOME")))
	{
		ft_printf("%wcd : %s not set\n", 2, "HOME");
		return (NULL);
	}
	else if (ft_strequ(dir, "-") && !(dir = ft_getenv("OLDPWD")))
	{
		ft_printf("%wcd : %s not set\n", 2, "OLDPWD");
		return (NULL);
	}
	if ((dir[0] == '/') || (dir[0] == '.' && (dir[1] == '/' || !dir[1])) ||
			(ft_strnequ(dir, "..", 2) || (dir[2] == '/' || !dir[2])))
		curpath = ft_strdup(dir);
	else if (!(curpath = get_envpathentry(dir, "CDPATH")))
		curpath = ft_strdup(dir);
	return (curpath);
}

int				bi_cd(char **av)
{
	char		*curpath;
	char		opt;
	int			i;
	int			exitcode;

	i = 0;
	curpath = NULL;
	while (av[++i] && (ft_strequ(av[i], "-P") || ft_strequ(av[i], "-L")))
		opt = av[i][1];
	if (!(curpath = get_curpath(av[i])))
		return (1);
	if (!(exitcode = handle_error(curpath)))
	{
		if (opt != 'P')
			curpath = convert_curpath(curpath);
		exitcode = change_dir(curpath, av[i], opt);
	}
	ft_strdel(&curpath);
	return (exitcode);
}
