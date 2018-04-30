/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_do_select_left.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 14:06:11 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/18 20:53:29 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"
#include <term.h>

static void	expand_selection(t_line *line)
{
	int	end;

	end = 0;
	if (line->cpos == line->nbc)
		end = 1;
	if (!end)
	{
		tputs(tgetstr("mr", 0), 1, &tputc);
		line_putchar(&line->str[line->cpos], line);
	}
	key_do_char_left(line, 0);
	if (!end)
		move_cur_left(line);
	tputs(tgetstr("me", 0), 1, &tputc);
}

static void	reduce_selection(t_line *line)
{
	key_do_char_left(line, 0);
	line_putchar(&line->str[line->cpos], line);
	move_cur_left(line);
}

void		key_do_select_left(t_line *line)
{
	if (line->cpos > 0)
	{
		if (line->sbeg == -1)
			line->sbeg = line->cpos;
		if (line->sbeg >= line->cpos)
			expand_selection(line);
		else
			reduce_selection(line);
	}
}
