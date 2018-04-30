/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_cmdline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:03:42 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/22 20:14:49 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include <libft.h>

char		*get_endofinput(char *prompt, char *s, int addnl, t_shell *shell)
{
	char	*eoi;
	char	*new;

	if (s)
	{
		if ((1 != get_cmdline(prompt, &eoi, shell)))
		{
			ft_strdel(&s);
			return (s);
		}
		if (addnl)
			new = ft_strcjoin(s, eoi, '\n');
		else
			new = ft_strjoin(s, eoi);
		ft_strdel(&s);
		ft_strdel(&eoi);
		s = new;
	}
	return (s);
}

t_lex		*lex_init(t_lex *lex, char *s)
{
	if (!lex)
		lex = ft_memalloc(sizeof(t_lex));
	if (lex)
	{
		lex->s = s;
		lex->i = 0;
		lex->b = -1;
		lex->e = -1;
		lex->isope = 0;
		lex->isescape = -1;
		lex->isquote = -1;
		lex->isdquote = -1;
		lex->curr_type = WORD;
	}
	return (lex);
}

int			check_endofinput(t_lex **alex, t_list **atokens, t_shell *shell)
{
	t_lex	*lex;

	lex = *alex;
	if (!CURR_CHAR)
	{
		if (lex->isescape >= 0)
			lex->s = get_endofinput("> ", lex->s, 1, shell);
		else if (lex->isdquote >= 0)
			lex->s = get_endofinput("dquote> ", lex->s, 1, shell);
		else if (lex->isquote >= 0)
			lex->s = get_endofinput("quote> ", lex->s, 1, shell);
		else if (lex->b == -1 && lex->prev_type == PIPE)
			lex->s = get_endofinput("pipe> ", lex->s, 1, shell);
		else
			return (0);
		ft_lstdel(atokens, &tok_del);
		lex_init(lex, lex->s);
	}
	*alex = lex;
	if (!lex->s)
		return (-1);
	return (0);
}

int			cmdline_tokenize(t_list **atokens, char **as, t_shell *shell)
{
	static t_lex	*lex = NULL;

	if (as && *as && (lex = lex_init(lex, *as)) && lex->s)
	{
		while (CURR_CHAR)
		{
			if (-1 == check_rules(atokens, lex, shell))
				return (-1);
			if (!CURR_CHAR && -1 == check_endofinput(&lex, atokens, shell))
				return (-1);
		}
		if (-1 == token_delimite(atokens, lex, shell))
			return (-1);
		*as = lex->s;
		return (0);
	}
	return (-1);
}
