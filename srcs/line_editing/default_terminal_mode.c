/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_terminal_mode.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:22:34 by mgalliou          #+#    #+#             */
/*   Updated: 2018/02/15 12:25:36 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <termios.h>
#include <term.h>
#include <unistd.h>

void						default_terminal_mode(void)
{
	static struct termios	tattr;
	static int				i = 0;

	if (!i)
	{
		tcgetattr(STDIN_FILENO, &tattr);
		tattr.c_lflag |= (ECHO | ISIG | ICANON);
		tattr.c_oflag |= (OPOST);
		i = 1;
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &tattr);
}
