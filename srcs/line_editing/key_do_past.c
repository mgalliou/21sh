/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_do_past.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:34:56 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/13 20:19:05 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

void	key_do_past(t_line *line)
{
	int	i;

	if (line->clipboard)
	{
		i = 0;
		while (line->clipboard[i])
		{
			line_reset_selection(line);
			cmdline_insert(&line->clipboard[i], 1, line);
			++i;
		}
	}
}
