/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_do_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:33:56 by mgalliou          #+#    #+#             */
/*   Updated: 2018/02/26 14:43:22 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

void		key_do_copy(t_line *line)
{
	int			beg;
	int			len;

	if (line->sbeg != -1)
	{
		if (line->clipboard)
			ft_strdel(&line->clipboard);
		if (line->sbeg < line->cpos)
		{
			beg = line->sbeg;
			len = line->cpos - line->sbeg;
		}
		else
		{
			beg = line->cpos;
			len = line->sbeg - line->cpos;
		}
		line->clipboard = ft_strndup(&line->str[beg], len + 1);
		line_reset_selection(line);
	}
}
