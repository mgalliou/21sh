/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 18:38:27 by edhommee          #+#    #+#             */
/*   Updated: 2018/04/22 16:22:28 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirections.h"
#include <limits.h>

int			ft_isnumber(char *src)
{
	int		i;

	i = 1;
	if (src[0] && src[0] != '+' && src[0] != '-' && !ft_isdigit(src[0]))
		return (0);
	if ((ft_strlen(src) == 10 && src[0] != '+' && src[0] != '-' &&
			ft_strcmp(src, "2147483647") > 0) ||
			(ft_strlen(src) == 11 && ((src[0] != '+' ||
			ft_strcmp(src, "+2147483647")) > 0 && (src[0] != '-' ||
			ft_strcmp(src, "-2147483648") > 0))) || ft_strlen(src) > 11)
		return (0);
	while (src[i])
	{
		if (!ft_isdigit(src[i]))
			return (0);
		i++;
	}
	return (1);
}

int			redirection_error(char *word, int i)
{
	char		*mes;

	if (i >= 0)
		return (i);
	if (i == -1)
		mes = "No such file";
	else if (i == -2)
		mes = "Permission denied";
	else if (i == -3)
		mes = "Redirection error";
	else if (i == -4)
		mes = "File number expected";
	else if (i == -5)
		mes = "is a directory";
	else if (i == -6)
		mes = "bad file descriptor";
	if (word)
		ft_printf("%w%s%s: %s\n", 2, "21sh: ", mes, word);
	else
		ft_printf("%w%s%s\n", 2, "21sh: ", mes);
	return (i);
}

int			is_redirection(t_tok *tok)
{
	if (tok->type == LESS || tok->type == GREAT || tok->type == DLESS ||
			tok->type == DGREAT || tok->type == LESSAND || tok->type == GREATAND
			|| tok->type == LESSGREAT || tok->type == CLOBBER ||
			tok->type == DLESSDASH)
		return (1);
	return (0);
}

int			dup_fd(int newfd, int oldfd)
{
	int		ret;

	ret = 0;
	if ((ret = dup2(newfd, oldfd)) >= 0)
		close(newfd);
	else
		redirection_error(NULL, -3);
	return (ret);
}

int			open_file(char *file, int oldfd, int flags, int mode)
{
	int		tmp;

	tmp = 0;
	if (get_stmode(file, 'D', 1))
		return (redirection_error(file, -5));
	if ((tmp = open(file, flags, mode)) < 0)
		return (redirection_error(file, -3));
	return (dup_fd(tmp, oldfd));
}
