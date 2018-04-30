/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_reprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 14:18:53 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/21 16:51:39 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"
#include <term.h>
#include <unistd.h>

void	line_reprint(int col, t_line *line)
{
	int	pos;

	pos = line->cpos;
	key_do_home(line);
	tputs(tgetstr("cr", 0), 1, &tputc);
	tputs(tgetstr("cd", 0), 1, &tputc);
	line->xpos = ft_strlen(line->prompt) % col;
	line->col = col;
	ft_putstr_fd(line->prompt, STDERR_FILENO);
	line_putstr(line->str, line);
	while (line->cpos < pos && !key_do_char_right(line, 0))
		;
}
