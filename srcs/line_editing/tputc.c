/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tputc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 16:05:52 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/13 19:47:47 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	tputc(int c)
{
	write(STDERR_FILENO, &c, 1);
	return (0);
}
