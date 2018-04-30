/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:22:57 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/21 16:43:39 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"
#include <term.h>

t_line	*line_update(t_line *line, t_shell *shell)
{
	int	tcol;

	if (line)
	{
		(void)shell;
		tcol = ft_getcol();
		if (tcol && tcol != line->col)
			line_reprint(tcol, line);
	}
	return (line);
}
