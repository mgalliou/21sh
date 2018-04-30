/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_quoting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:53:48 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/22 19:42:08 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	start_quoting(t_lex *lex)
{
	if (CURR_CHAR == '\\')
	{
		if (NEXT_CHAR == '\n')
			lex->i += 2;
		else
			lex->isescape = lex->i;
	}
	else if (CURR_CHAR == '\'')
		lex->isquote = lex->i;
	else if (CURR_CHAR == '\"')
		lex->isdquote = lex->i;
}
