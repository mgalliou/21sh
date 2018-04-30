/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_putchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:01:09 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/13 19:40:20 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"
#include <unistd.h>

void				line_putchar(char *s, t_line *line)
{
	ft_putchar_fd(*s, STDERR_FILENO);
	++line->xpos;
}
