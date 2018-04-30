/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isquoted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:34:54 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/14 13:45:41 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		isquoted(t_lex *lex)
{
	if (lex->isescape >= 0 || lex->isquote >= 0 || lex->isdquote >= 0)
		return (1);
	return (0);
}