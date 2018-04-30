/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:30:31 by edhommee          #+#    #+#             */
/*   Updated: 2018/04/15 15:55:44 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <limits.h>

static t_redir	*redir_new(int in, t_tok_type type, char *word)
{
	t_redir		*new;

	if ((new = ft_memalloc(sizeof(t_redir))))
	{
		new->in = in;
		new->type = type;
		new->rec = dup(new->in);
		new->word = word;
	}
	return (new);
}

t_redir			*get_redir(t_list *prev, t_list *red)
{
	int				in;
	char			*word;
	t_tok_type		type;

	in = -1;
	word = NULL;
	type = ((t_tok*)red->content)->type;
	if (prev && tok_isoftype(prev, IO_NUMBER))
		in = ft_atoi(((t_tok*)prev->content)->s);
	else if (type == LESS || type == LESSAND || type == LESSGREAT ||
			type == DLESS || type == DLESSDASH)
		in = 0;
	else if (type == GREAT || type == DGREAT || type == GREATAND ||
			type == CLOBBER)
		in = 1;
	if (red && tok_isoftype(red->next, WORD))
		word = ((t_tok*)red->next->content)->s;
	else
		return (NULL);
	return (redir_new(in, type, word));
}
