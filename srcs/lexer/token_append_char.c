/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_append_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:56:49 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/22 18:48:09 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	token_append_char(t_lex *lex)
{
	if (lex)
	{
		if (lex->isdquote >= 0 && lex->isdquote < lex->i &&
				CURR_CHAR == '\"' && lex->isescape == -1)
			lex->isdquote = -1;
		if (lex->isquote >= 0 && lex->isquote < lex->i && CURR_CHAR == '\''
				&& lex->isescape == -1)
			lex->isquote = -1;
		if (lex->isescape >= 0 && lex->isescape < lex->i)
			lex->isescape = -1;
		lex->e = lex->i++;
	}
}
