/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raw_terminal_mode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:21:56 by mgalliou          #+#    #+#             */
/*   Updated: 2018/03/06 13:03:31 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <termios.h>
#include <term.h>
#include <unistd.h>

void						raw_terminal_mode(void)
{
	static struct termios	tattr;
	static int				i = 0;

	if (!i)
	{
		tcgetattr(STDIN_FILENO, &tattr);
		tattr.c_lflag &= ~(ECHO | ISIG | ICANON);
		tattr.c_oflag &= ~(OPOST);
		tattr.c_cc[VMIN] = 0;
		tattr.c_cc[VTIME] = 1;
		tgetent(NULL, ft_getenv(ttyname(0)));
		i = 1;
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &tattr);
}
