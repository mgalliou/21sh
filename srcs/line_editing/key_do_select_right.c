/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_do_select_right.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 14:05:26 by mgalliou          #+#    #+#             */
/*   Updated: 2018/02/26 14:47:57 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"
#include <term.h>

static void	expand_selection(t_line *line)
{
	tputs(tgetstr("mr", 0), 1, &tputc);
	line_putchar(&line->str[line->cpos], line);
	key_do_char_right(line, 0);
	move_cur_left(line);
	tputs(tgetstr("me", 0), 1, &tputc);
}

static void	reduce_selection(t_line *line)
{
	key_do_char_right(line, 0);
	line_putchar(&line->str[line->cpos], line);
	move_cur_left(line);
}

void		key_do_select_right(t_line *line)
{
	if (line->cpos < line->nbc - 1)
	{
		if (line->sbeg == -1)
			line->sbeg = line->cpos;
		if (line->sbeg <= line->cpos)
			expand_selection(line);
		else
			reduce_selection(line);
	}
}
