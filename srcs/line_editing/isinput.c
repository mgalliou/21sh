/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isinput.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 15:03:15 by mgalliou          #+#    #+#             */
/*   Updated: 2018/02/26 15:15:33 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		isinput(char *i, char *s)
{
	int	l;

	l = ft_strlen(i);
	if (ft_strnequ(i, s, l))
		return (l);
	return (0);
}
