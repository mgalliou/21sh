/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdotdot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 13:13:03 by mgalliou          #+#    #+#             */
/*   Updated: 2017/10/17 15:19:57 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	isdotdot(char *path)
{
	if (path && ft_strlen(path) >= 2 &&
			ft_strnequ(path, "..", 2) && (path[2] == '/' || !path[2]))
		return (1);
	return (0);
}
