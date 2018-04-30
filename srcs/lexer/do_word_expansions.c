/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_word_expansions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 18:34:00 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/22 20:29:37 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	isdquotespechar(char c)
{
	if (c && ft_strchr("$`\"\\", c))
		return (1);
	return (0);
}

static char	*expand_dquote(char *s, int *ai)
{
	int		i;

	i = *ai;
	ft_strcpy(&s[i], &s[i + 1]);
	while (s[i] && s[i] != '\"')
	{
		if (s[i] == '\\' && isdquotespechar(s[i + 1]))
			ft_strcpy(&s[i], &s[i + 1]);
		++i;
	}
	ft_strcpy(&s[i], &s[i + 1]);
	*ai = i - 1;
	return (s);
}

static char	*expand_quote(char *s, int *ai)
{
	int			i;

	i = *ai;
	ft_strcpy(&s[i], &s[i + 1]);
	while (s[i] && s[i] != '\'')
		++i;
	ft_strcpy(&s[i], &s[i + 1]);
	*ai = i - 1;
	return (s);
}

char		*do_word_expansions(char *s)
{
	int		i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == '\\')
			ft_strcpy(&s[i], &s[i + 1]);
		else if (s[i] == '\'')
			expand_quote(s, &i);
		else if (s[i] == '\"')
			expand_dquote(s, &i);
		++i;
	}
	return (s);
}
