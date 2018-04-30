/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cur_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 14:22:28 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/23 14:47:54 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"
#include <term.h>
#include <unistd.h>

void	move_cur_right(t_line *line)
{
	++line->xpos;
	ft_putchar_fd(line->str[line->cpos], STDERR_FILENO);
	if (line->xpos == line->col)
	{
		tputs(tgetstr("do", 0), 1, &tputc);
		tputs(tgetstr("cr", 0), 1, &tputc);
		line->xpos = 0;
	}
}
