/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_do_char_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 12:41:30 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/21 16:30:03 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		key_do_char_left(t_line *line, int resetsel)
{
	if (line->cpos)
	{
		if (resetsel)
			line_reset_selection(line);
		move_cur_left(line);
		--line->cpos;
		return (0);
	}
	return (-1);
}
