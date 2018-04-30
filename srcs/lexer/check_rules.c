/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 18:16:19 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/22 20:20:05 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static	int	lx_isblank(char c)
{
	if (ft_isblank(c) || c == '\n')
		return (1);
	return (0);
}

static void	token_start(t_lex *lex)
{
	if (lex)
	{
		lex->b = lex->i;
		lex->e = lex->i;
		if (lex->isope)
		{
			if (CURR_CHAR == '\n')
				lex->curr_type = NEWLINE;
			else if (CURR_CHAR == ';')
				lex->curr_type = SEMI;
			else if (CURR_CHAR == '<')
				lex->curr_type = LESS;
			else if (CURR_CHAR == '>')
				lex->curr_type = GREAT;
			else if (CURR_CHAR == '|')
				lex->curr_type = PIPE;
			else
				lex->curr_type = WORD;
		}
		lex->i++;
	}
}

static int	check_rule_3(t_lex *lex)
{
	if (lex && lex->b > -1 && lex->i > lex->b && lex->isope
			&& !curr_word_isope(lex))
		return (1);
	return (0);
}

static int	check_rule_2(t_lex *lex)
{
	if (lex && lex->b > -1 && lex->i > lex->b && !isquoted(lex) &&
			lex->isope && curr_word_isope(lex))
		return (1);
	return (0);
}

int			check_rules(t_list **atokens, t_lex *lex, t_shell *shell)
{
	if (check_rule_2(lex))
		lex->e = lex->i++;
	else if (check_rule_3(lex) && (-1 == token_delimite(atokens, lex, shell)))
		return (-1);
	else if ((!isquoted(lex) && isquotechar(CURR_CHAR)) ||
			(lex->isescape < 0 && lex->isquote < 0 && CURR_CHAR == '\\'))
		start_quoting(lex);
	else if (!isquoted(lex) && isbegofopechar(CURR_CHAR))
	{
		if (-1 == token_delimite(atokens, lex, shell))
			return (-1);
		lex->isope = 1;
		token_start(lex);
	}
	else if (!isquoted(lex) && lx_isblank(CURR_CHAR))
	{
		if (-1 == token_delimite(atokens, lex, shell))
			return (-1);
		lex->i++;
	}
	else if (lex->b > -1 && lex->e == lex->i - 1)
		token_append_char(lex);
	else
		token_start(lex);
	return (0);
}
