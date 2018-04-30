/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cur_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 14:21:17 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/21 15:17:32 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"
#include <term.h>

static void	move_cur_eol(t_line *line)
{
	while (line->xpos < line->col - 1)
	{
		tputs(tgetstr("nd", 0), 1, &tputc);
		++line->xpos;
	}
}

void		move_cur_left(t_line *line)
{
	if (!line->xpos)
	{
		tputs(tgetstr("up", 0), 1, &tputc);
		move_cur_eol(line);
	}
	else
	{
		--line->xpos;
		tputs(tgetstr("le", 0), 1, &tputc);
	}
}
