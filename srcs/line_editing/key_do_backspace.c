/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_do_backspace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 18:19:09 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/19 11:31:01 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"
#include <term.h>

void	key_do_backspace(t_line *line)
{
	if (line->nbc && line->cpos)
	{
		line->str[--line->cpos] = '\0';
		--line->nbc;
		move_cur_left(line);
		tputs(tgetstr("cd", 0), 1, &tputc);
		if (line->str[line->cpos + 1])
			ft_strcpy(&line->str[line->cpos], &line->str[line->cpos + 1]);
		line_putstr(&line->str[line->cpos], line);
	}
}
