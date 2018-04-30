/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_do_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 17:02:09 by mgalliou          #+#    #+#             */
/*   Updated: 2018/02/22 13:49:09 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"
#include <term.h>

void	key_do_delete(t_line *line)
{
	if (line->nbc && line->cpos < line->nbc)
	{
		--line->nbc;
		tputs(tgetstr("cd", 0), 1, &tputc);
		if (line->str[line->cpos])
			ft_strcpy(&line->str[line->cpos], &line->str[line->cpos + 1]);
		line_putstr(&line->str[line->cpos], line);
	}
}
