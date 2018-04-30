/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdline_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 16:37:03 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/13 19:22:07 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"
#include <unistd.h>
#include <term.h>

int					cmdline_insert(char *s, int print, t_line *line)
{
	while (line->nbc + 1 > line->ssize)
	{
		line->ssize += BUFF_SIZE;
		line->str = ft_strrealloc(line->str, line->ssize + 1);
	}
	if (line->cpos < line->nbc)
		ft_memmove(&line->str[line->cpos + 1], &line->str[line->cpos],
				ft_strlen(&line->str[line->cpos]));
	if ((line->str[line->cpos] = *s) && print)
	{
		line_putstr(&line->str[line->cpos], line);
		move_cur_right(line);
		++line->cpos;
		++line->nbc;
	}
	return (1);
}
