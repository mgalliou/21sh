/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lineinit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:57:42 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/19 13:59:53 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"
#include <termios.h>
#include <unistd.h>
#include <libft.h>

static t_line	*first_time_init(t_line *line)
{
	if (!(line = ft_memalloc(sizeof(t_line))))
		return (NULL);
	if (!(line->input = ft_strnew(BUFF_SIZE)))
	{
		ft_memdel((void*)&line);
		return (NULL);
	}
	line->i = 0;
	line->isize = BUFF_SIZE;
	line->ilen = 0;
	line->clipboard = NULL;
	return (line);
}

int				line_init(char *prompt, t_line **aline)
{
	t_line		*line;

	line = *aline;
	if (!line)
		line = first_time_init(line);
	if (!line || !isatty(STDIN_FILENO) || !(line->col = ft_getcol()))
		return (-1);
	if ((line->prompt = prompt))
		ft_putstr_fd(line->prompt, STDERR_FILENO);
	line->str = ft_strnew(BUFF_SIZE);
	line->ssize = BUFF_SIZE;
	line->cpos = 0;
	line->xpos = ft_strlen(line->prompt) % line->col;
	line->hpos = -1;
	line->stop = 1;
	line->nbc = 0;
	line->sbeg = -1;
	*aline = line;
	return (0);
}
