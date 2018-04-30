/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curr_word_isope.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:43:37 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/15 15:51:17 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int				curr_word_isope(t_lex *lex)
{
	static char	*op[] = {OP_NEWLINE, OP_SEMI, OP_AND_IF, OP_OR_IF,
		OP_LESS, OP_GREAT, OP_DLESS, OP_DGREAT, OP_LESSAND, OP_GREATAND,
		OP_LESSGREAT, OP_DLESSDASH, OP_CLOBBER, OP_PIPE, NULL};
	int			i;
	char		*s;
	int			len;

	if (lex && lex->s)
	{
		s = &lex->s[lex->b];
		len = lex->i - lex->b + 1;
		i = 0;
		while (op[i])
		{
			if (ft_strnequ(op[i], s, len))
			{
				lex->curr_type = i;
				return (1);
			}
			i++;
		}
	}
	return (0);
}
