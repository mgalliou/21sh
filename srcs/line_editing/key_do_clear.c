/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_do_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 18:17:45 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/13 19:47:24 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"
#include <term.h>

void	key_do_clear(t_line *line)
{
	default_terminal_mode();
	tputs(tgetstr("cl", 0), 1, &tputc);
	ft_putstr(line->prompt);
	ft_putstr(line->str);
	raw_terminal_mode();
}
