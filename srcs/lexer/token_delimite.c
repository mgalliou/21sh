/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_delimite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:44:43 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/21 13:10:28 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int		curr_is_io_nbr(t_lex *lex)
{
	int			i;

	i = lex->b;
	while (lex->s[i] && i <= lex->e)
	{
		if (!ft_isdigit(lex->s[i]))
			return (0);
		++i;
	}
	if (lex->s[lex->e + 1] == '<' || lex->s[lex->e + 1] == '>')
		return (1);
	return (0);
}

static t_tok	*tok_new(t_lex *lex)
{
	t_tok		*new;

	if (!(new = ft_memalloc(sizeof(t_tok))))
		return (NULL);
	if (!(new->s = ft_strsub(lex->s, lex->b, lex->e - lex->b + 1)))
	{
		tok_del(&new, 0);
		return (NULL);
	}
	new->b = lex->b;
	new->e = lex->e;
	new->type = lex->curr_type;
	if (curr_is_io_nbr(lex))
		new->type = IO_NUMBER;
	return (new);
}

int				token_delimite(t_list **atokens, t_lex *lex, t_shell *shell)
{
	t_tok		*new;
	t_list		*token;

	if (lex->b > -1)
	{
		if (!(new = tok_new(lex)) ||
				(!(token = ft_lstnewnocpy(new, sizeof(t_tok)))))
			return (-1);
		ft_lstaddback(atokens, token);
		if (new->type == WORD)
		{
			if ((lex->prev_type == DLESS || lex->prev_type == DLESSDASH)
					&& (-1 == do_heredoc(&(new->s), shell)))
				return (-1);
			new->s = do_word_expansions(new->s);
		}
		lex->prev_type = lex->curr_type;
		lex->b = -1;
		lex->e = -1;
		lex->isope = 0;
		lex->curr_type = WORD;
	}
	return (0);
}
