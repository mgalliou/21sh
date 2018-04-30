/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_prev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 13:34:46 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/22 15:33:26 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"
#include <term.h>

void		history_prev(t_line *line, t_shell *shell)
{
	if (shell->historylen && line->hpos)
	{
		if (line->hpos == -1)
		{
			ft_strdel(&line->firststr);
			line->firststr = ft_strdup(line->str);
			line->hpos = shell->historylen - 1;
		}
		else
			--line->hpos;
		line_replace(shell->history[line->hpos], line);
	}
}
