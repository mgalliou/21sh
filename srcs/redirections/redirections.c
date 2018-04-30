/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:53:42 by edhommee          #+#    #+#             */
/*   Updated: 2018/04/15 16:27:59 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirections.h"

int			red_less(t_redir *red)
{
	if (access(red->word, F_OK) != 0)
		return (redirection_error(red->word, -1));
	else if (access(red->word, R_OK) != 0)
		return (redirection_error(red->word, -2));
	return (open_file(red->word, red->in, O_RDONLY, 0));
}

int			red_great(t_redir *red)
{
	if (access(red->word, F_OK) == 0 && access(red->word, W_OK) != 0)
		return (redirection_error(red->word, -2));
	return (open_file(red->word, red->in, O_WRONLY | O_CREAT | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH));
}

int			red_dless(t_redir *red)
{
	int		tmp;
	int		fd[2];

	if (pipe(fd) != 0)
		return (redirection_error(NULL, -3));
	tmp = fork();
	if (!tmp)
	{
		close(fd[0]);
		if (red->word && ft_strlen(red->word) > 0)
			ft_putendl_fd(red->word, fd[1]);
		exit(0);
	}
	close(fd[1]);
	return (dup_fd(fd[0], red->in));
}

int			red_dgreat(t_redir *red)
{
	if (access(red->word, F_OK) == 0 && access(red->word, W_OK) != 0)
		return (redirection_error(red->word, -2));
	return (open_file(red->word, red->in, O_WRONLY | O_APPEND | O_CREAT,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH));
}

int			red_lessgreat(t_redir *red)
{
	if (access(red->word, F_OK) == 0 && access(red->word, W_OK) != 0)
		return (redirection_error(red->word, -2));
	return (open_file(red->word, red->in, O_RDWR | O_CREAT,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH));
}
