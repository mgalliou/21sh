/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_do_char_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 12:43:23 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/21 16:29:25 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int	key_do_char_right(t_line *line, int resetsel)
{
	if (line->cpos < line->nbc)
	{
		if (resetsel)
			line_reset_selection(line);
		move_cur_right(line);
		++line->cpos;
		return (0);
	}
	return (-1);
}
