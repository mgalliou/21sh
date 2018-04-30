/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   istermcap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 18:29:14 by mgalliou          #+#    #+#             */
/*   Updated: 2018/02/16 17:22:56 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <term.h>

int		istermcap(char *tc, char *s)
{
	char		*t;
	char		len;

	t = tgetstr(tc, NULL);
	if (t && (ft_strequ(tc, "kl") || ft_strequ(tc, "kr") ||
			ft_strequ(tc, "ku") || ft_strequ(tc, "kd")))
		t[1] = 91;
	if (t && (ft_strnequ(t, s, (len = ft_strlen(t)))))
		return (len);
	return (0);
}
