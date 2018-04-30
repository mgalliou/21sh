/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_putstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:10:02 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/12 18:51:25 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"
#include <term.h>

void				line_putstr(char *s, t_line *line)
{
	int				i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			if (line->xpos == line->col)
			{
				tputs(tgetstr("do", 0), 1, &tputc);
				tputs(tgetstr("cr", 0), 1, &tputc);
				line->xpos = 0;
			}
			line_putchar(&s[i], line);
			i++;
		}
		while (i)
		{
			move_cur_left(line);
			i--;
		}
	}
}
