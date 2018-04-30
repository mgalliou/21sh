/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_isseparator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:14:18 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/15 16:14:55 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	tok_isseparator(t_list *token)
{
	if (token && (tok_isoftype(token, NEWLINE) || tok_isoftype(token, SEMI) ||
			tok_isoftype(token, AND_IF) || tok_isoftype(token, OR_IF) ||
			tok_isoftype(token, PIPE)))
		return (1);
	return (0);
}
