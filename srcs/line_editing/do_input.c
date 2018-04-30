/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 17:01:59 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/21 16:40:39 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"
#include <term.h>

static	int		do_atl_escape_input(char *s, t_line *line)
{
	int			len;

	if ((len = istermcap("kl", &s[1])))
		key_do_word_left(line);
	else if ((len = istermcap("kr", &s[1])))
		key_do_word_right(line);
	else if ((len = istermcap("ku", &s[1])))
		key_do_line_up(line);
	else if ((len = istermcap("kd", &s[1])))
		key_do_line_down(line);
	else
		len = 1;
	return (len + 1);
}

static int		do_escape_input(char *s, t_line *line, t_shell *shell)
{
	int			len;

	if (s[1] == '\e')
		len = do_atl_escape_input(s, line);
	else if ((len = istermcap("kl", s)))
		key_do_char_left(line, 1);
	else if ((len = istermcap("kr", s)))
		key_do_char_right(line, 1);
	else if ((len = isinput("\x1b\x5b\x31\x3b\x32\x44", s)))
		key_do_select_left(line);
	else if ((len = isinput("\x1b\x5b\x31\x3b\x32\x43", s)))
		key_do_select_right(line);
	else if ((len = istermcap("ku", s)))
		history_prev(line, shell);
	else if ((len = istermcap("kd", s)))
		history_next(line, shell);
	else if ((len = istermcap("kD", s)))
		key_do_delete(line);
	else
		len = 1;
	return (len);
}

static int		isbackspaceinput(char *s)
{
	int			len;

	if ((len = istermcap("kb", s)))
		return (len);
	else if ((len = isinput("\x7F", s)))
		return (len);
	return (0);
}

static int		do_onechar_input(char *s, t_line *line, t_shell *shell)
{
	int			len;

	if ((len = isinput("\n", s)))
		key_do_return(line);
	else if ((len = isinput("\x01", s)))
		key_do_home(line);
	else if ((len = isinput("\x03", s)))
		key_do_ctrl_c(line);
	else if ((len = isinput("\x04", s) && !line->nbc))
		key_do_ctrl_d(line, shell);
	else if ((len = isinput("\x05", s)))
		key_do_end(line);
	else if ((len = isinput("\t", s)))
		key_do_complete(line, shell);
	else if ((len = isinput("\x19", s)))
		key_do_copy(line);
	else if ((len = isinput("\x10", s)))
		key_do_past(line);
	else if ((len = isinput("\x0C", s)))
		key_do_clear(line);
	else
		len = 1;
	return (len);
}

int				do_input(char *s, t_line *line, t_shell *shell)
{
	int			len;

	if (isvalidchar(*s))
		len = cmdline_insert(s, 1, line);
	else if (*s == '\e')
		len = do_escape_input(s, line, shell);
	else if ((len = isbackspaceinput(s)))
		key_do_backspace(line);
	else
		len = do_onechar_input(s, line, shell);
	return (len);
}
