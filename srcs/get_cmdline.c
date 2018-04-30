/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmdline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 20:08:31 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/13 20:15:47 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>
#include <unistd.h>

int	get_cmdline(char *prompt, char **acmdline, t_shell *shell)
{
	if (shell->isinteractive)
		return (get_and_edit_line(prompt, acmdline, shell));
	else
		return (get_next_line(STDIN_FILENO, acmdline));
}
