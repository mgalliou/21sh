/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_reset_selection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 20:33:00 by mgalliou          #+#    #+#             */
/*   Updated: 2018/02/26 14:32:59 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

void	line_reset_selection(t_line *line)
{
	int	i;

	if (line->sbeg != -1)
	{
		line->sbeg = -1;
		i = line->cpos;
		key_do_home(line);
		line_putstr(line->str, line);
		while (i)
		{
			key_do_char_right(line, 0);
			i--;
		}
	}
}
