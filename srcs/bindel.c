/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bindel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 10:54:15 by mgalliou          #+#    #+#             */
/*   Updated: 2018/03/17 15:56:18 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void		bindel(void *abin)
{
	t_bin	*bin;

	bin = abin;
	if (bin)
	{
		ft_strdel(&(bin->path));
		ft_memdel((void*)&bin);
		bin = NULL;
	}
}
