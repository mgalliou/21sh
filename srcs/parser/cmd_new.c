/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:12:16 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/14 19:40:33 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int		get_cmdredir(t_list *tokens, t_list **redir)
{
	t_list		*beg;
	t_list		*prev;
	t_redir		*new;

	prev = NULL;
	beg = tokens;
	while (beg && !tok_isseparator(beg))
	{
		if (is_redirection(beg->content))
		{
			if ((new = get_redir(prev, beg)))
				ft_lstaddback(redir, ft_lstnewnocpy(new, sizeof(t_redir)));
			else
				return (-1);
			if (beg->next)
				((t_tok*)beg->next->content)->type = WORD_REDIR;
		}
		prev = beg;
		beg = beg->next;
	}
	return (0);
}

static int		get_word_nbr(t_list *tokens)
{
	int			n;

	n = 0;
	while (tokens && !tok_isseparator(tokens))
	{
		if (tok_isoftype(tokens, WORD))
			++n;
		tokens = tokens->next;
	}
	return (n);
}

static char		**get_cmdav(t_list *tokens)
{
	int			n;
	char		**cmdav;

	cmdav = NULL;
	n = get_word_nbr(tokens);
	if (n && (cmdav = ft_memalloc(sizeof(char*) * (n + 1))))
	{
		n = 0;
		while (tokens && !tok_isseparator(tokens))
		{
			if (tok_isoftype(tokens, WORD))
				cmdav[n++] = ((t_tok*)tokens->content)->s;
			tokens = tokens->next;
		}
		cmdav[n] = NULL;
	}
	return (cmdav);
}

t_cmd			*cmd_new(t_list *tokens)
{
	t_cmd		*new;

	if ((new = ft_memalloc(sizeof(t_cmd))))
	{
		new->av = NULL;
		new->redir = NULL;
		new->sep = ((t_tok*)tokens->content)->type;
		if (tok_isseparator(tokens))
			tokens = tokens->next;
		if (get_cmdredir(tokens, &new->redir) != 0)
		{
			cmd_del(new, 0);
			return (NULL);
		}
		else
			new->av = get_cmdav(tokens);
	}
	return (new);
}
