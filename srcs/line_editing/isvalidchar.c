/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvalidchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 15:06:08 by mgalliou          #+#    #+#             */
/*   Updated: 2018/02/26 15:15:23 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

/*
**int		isvalidchar(int c)
**{
**	if (c && ((ft_isprint(c) || (c > 0x80 && c <= 0xFF)) ||
**			((c & 0x80) && !(c & 0x40)) ||
**			((c & 0xC0) && !(c & 0x20)) ||
**			((c & 0xE0) && !(c & 0x10)) ||
**			((c & 0xF0) && !(c & 0x08))))
**		return (1);
**	return (0);
**}
*/

int		isvalidchar(int c)
{
	if (c && ft_isprint(c) && ft_isascii(c))
		return (1);
	return (0);
}
