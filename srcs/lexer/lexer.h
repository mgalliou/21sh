/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 12:08:04 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/18 15:48:53 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <shell.h>

# define OP_NEWLINE		"\n"
# define OP_SEMI		";"
# define OP_AND_IF		"&&"
# define OP_OR_IF		"||"
# define OP_DSEMI		";;"
# define OP_LESS		"<"
# define OP_GREAT		">"
# define OP_DLESS		"<<"
# define OP_DGREAT		">>"
# define OP_LESSAND 	"<&"
# define OP_GREATAND	">&"
# define OP_LESSGREAT	"<>"
# define OP_DLESSDASH	"<<-"
# define OP_CLOBBER		">|"
# define OP_PIPE		"|"
# define OP_AMPERSAND	"&"

# define OP_CHARS		"\n;&|<>&-"
# define QUOTE_CHARS    "\\\'\""

typedef struct	s_lex
{
	char		*s;
	int			i;
	int			b;
	int			e;
	int			isope;
	int			isescape;
	int			isquote;
	int			isdquote;
	int			lastisheredoc;
	t_tok_type	curr_type;
	t_tok_type	prev_type;
}				t_lex;

# define PREV_CHAR lex->s[lex->i - 1]
# define CURR_CHAR lex->s[lex->i]
# define NEXT_CHAR lex->s[lex->i + 1]

/*
**	s : input
**	i : current char
**	b : beginning of the delimited token ( -1 if not delimited)
**	e : end of the delimited token ( -1 if not delimited)
*/

int				check_rules(t_list **atokens, t_lex *lex, t_shell *shell);
int				curr_word_isope(t_lex *lex);
void			start_quoting(t_lex *lex);
void			token_append_char(t_lex *lex);
int				token_delimite(t_list **atokens, t_lex *lex, t_shell *shell);
char			*do_word_expansions(char *s);
int				do_heredoc(char **aeoi, t_shell *shell);

int				isopechar(char c);
int				isquotechar(char c);
int				isbegofopechar(char c);
int				isquoted(t_lex *lex);

#endif
