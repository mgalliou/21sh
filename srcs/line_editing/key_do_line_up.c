/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_do_line_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:09:50 by mgalliou          #+#    #+#             */
/*   Updated: 2018/02/24 13:04:34 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

void	key_do_line_up(t_line *line)
{
	int	i;

	if (line->cpos >= line->col)
	{
		i = 0;
		while (i < line->col)
		{
			key_do_char_left(line, 1);
			i++;
		}
	}
}
