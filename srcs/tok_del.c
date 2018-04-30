/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:02:42 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/17 20:54:58 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void	tok_del(void *p, size_t size)
{
	t_tok	*tok;

	(void)size;
	tok = p;
	if (tok)
	{
		if (tok->s)
			ft_strdel(&(tok->s));
		ft_memdel((void*)&tok);
		p = NULL;
	}
}
