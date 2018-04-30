/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_do_ctrl_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 21:07:59 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/18 21:15:04 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

void	key_do_ctrl_d(t_line *line, t_shell *shell)
{
	(void)line;
	default_terminal_mode();
	ft_putchar('\n');
	exit(shell->exitcode);
}
