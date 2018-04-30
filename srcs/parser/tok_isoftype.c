/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_isoftype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:09:33 by mgalliou          #+#    #+#             */
/*   Updated: 2018/03/29 16:22:01 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

int	tok_isoftype(t_list *token, t_tok_type type)
{
	if (token && ((t_tok*)token->content)->type == type)
		return (1);
	return (0);
}
