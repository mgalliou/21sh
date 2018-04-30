/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 19:38:15 by edhommee          #+#    #+#             */
/*   Updated: 2018/04/19 13:58:13 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		tokens_read(t_list **acmds, t_list *tokens)
{
	t_cmd	*cmd;
	int		err;

	if (!tokens)
		return (-1);
	err = (tok_isseparator(tokens) && !tok_isoftype(tokens, NEWLINE)) ? -1 : 0;
	while (tokens && !err && (cmd = cmd_new(tokens)))
	{
		ft_lstaddback(acmds, ft_lstnewnocpy(cmd, sizeof(cmd)));
		if (tok_isseparator(tokens))
			tokens = tokens->next;
		if (tok_isseparator(tokens))
			err = -1;
		while (!err && tokens && !tok_isseparator(tokens))
			tokens = tokens->next;
	}
	err = (tokens) ? -1 : err;
	if (err && tokens)
		ft_printf("%wparse error near token '%s'\n", 2,
				((t_tok*)tokens->content)->s);
	return (err);
}
