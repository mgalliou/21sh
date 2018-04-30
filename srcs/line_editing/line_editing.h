/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editing.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:22:45 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/21 16:40:52 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_EDITING_H
# define LINE_EDITING_H

# include <shell.h>
# define BUFF_SIZE 128
# define MAX_KEY_LEN 7

typedef struct		s_line
{
	char			*prompt;
	char			*input;
	int				i;
	int				stop;
	int				isize;
	int				ilen;
	char			*str;
	int				ssize;
	int				nbc;
	int				cpos;
	int				col;
	int				xpos;
	int				hpos;
	int				sbeg;
	int				wbeg;
	char			*clipboard;
	char			*firststr;
}					t_line;

int					line_init(char *prompt, t_line **aline);
t_line				*line_update(t_line *line, t_shell *shell);
void				line_putchar(char *s, t_line *line);
void				line_putstr(char *s, t_line *line);
void				line_replace(char *s, t_line *line);
void				line_reprint(int col, t_line *line);
void				line_reset_selection(t_line *line);

int					read_input(t_line *line, t_shell *shell);
int					cmdline_insert(char *s, int print, t_line *line);

int					do_input(char *s, t_line *line, t_shell *shell);
void				key_do_clear(t_line *line);
void				key_do_backspace(t_line *line);
int					key_do_char_left(t_line *line, int	resetsel);
int					key_do_char_right(t_line *line, int resetsel);
void				key_do_ctrl_c(t_line *line);
void				key_do_ctrl_d(t_line *line, t_shell *shell);
void				key_do_complete(t_line *line, t_shell *shell);
void				key_do_delete(t_line *line);
void				key_do_home(t_line *line);
void				key_do_end(t_line *line);
void				key_do_word_left(t_line *line);
void				key_do_word_right(t_line *line);
void				key_do_line_up(t_line *line);
void				key_do_line_down(t_line *line);
void				key_do_select_left(t_line *line);
void				key_do_select_right(t_line *line);
void				key_do_copy(t_line *line);
void				key_do_past(t_line *line);
void				key_do_return(t_line *line);

void				move_cur_left(t_line *line);
void				move_cur_right(t_line *line);

void				history_prev(t_line *line, t_shell *shell);
void				history_next(t_line *line, t_shell *shell);

int					tputc(int c);
int					isvalidchar(int c);
int					istermcap(char *tc, char *s);
int					isinput(char *i, char *s);

#endif
