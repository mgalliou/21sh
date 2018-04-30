/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_do_line_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:10:19 by mgalliou          #+#    #+#             */
/*   Updated: 2018/02/24 13:04:21 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

void	key_do_line_down(t_line *line)
{
	int	i;

	if (line->nbc - line->cpos >= line->col)
	{
		i = 0;
		while (i < line->col)
		{
			key_do_char_right(line, 1);
			i++;
		}
	}
}
