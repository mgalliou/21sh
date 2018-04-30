/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_replace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 13:48:54 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/22 15:33:43 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"
#include <term.h>

void	line_replace(char *s, t_line *line)
{
	if (s)
	{
		key_do_home(line);
		tputs(tgetstr("cd", 0), 1, &tputc);
		ft_strdel(&line->str);
		line->str = ft_strdup(s);
		default_terminal_mode();
		ft_putstr(line->str);
		raw_terminal_mode();
		line->nbc = ft_strlen(line->str);
		line->ssize = line->nbc;
		line->cpos = line->nbc;
		line->xpos = (ft_strlen(line->prompt) + line->nbc) % line->col;
	}
}
