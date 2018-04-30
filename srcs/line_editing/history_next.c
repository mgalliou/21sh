/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 13:35:37 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/22 15:33:50 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"
#include <term.h>

void	history_next(t_line *line, t_shell *shell)
{
	if (line->hpos >= 0 && line->hpos < shell->historylen)
	{
		if (line->hpos < shell->historylen - 1)
		{
			++line->hpos;
			line_replace(shell->history[line->hpos], line);
		}
		else
		{
			line_replace(line->firststr, line);
			ft_strdel(&line->firststr);
			line->hpos = -1;
		}
	}
}
