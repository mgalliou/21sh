/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isquotechar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:49:29 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/05 18:21:36 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		isquotechar(char c)
{
	if (c && ft_strchr(QUOTE_CHARS, c))
		return (1);
	return (0);
}
