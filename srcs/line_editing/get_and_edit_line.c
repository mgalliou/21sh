/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_edit_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 10:47:56 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/21 13:05:11 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"
#include <libft.h>
#include <unistd.h>

/*
**void				print_buf(char *buf)
**{
**	default_terminal_mode();
**	ft_printf("\n");
**	while (*buf)
**		ft_printf("[%1$3d / %1$3x]", *buf++);
**	raw_terminal_mode();
**}
*/

static int			get_input(t_line *line)
{
	int				ret;
	char			buf[MAX_KEY_LEN];

	ret = MAX_KEY_LEN;
	while (ret == MAX_KEY_LEN)
	{
		ft_bzero(buf, MAX_KEY_LEN);
		ret = read(STDIN_FILENO, buf, MAX_KEY_LEN);
		if (!ret || ret == -1)
			return (0);
		while (line->isize < line->ilen + ret)
		{
			line->isize += BUFF_SIZE;
			line->input = ft_strrealloc(line->input, line->isize + 1);
		}
		ft_strcpy(&line->input[line->ilen], buf);
		line->ilen += ret;
	}
	return (1);
}

int					get_and_edit_line(char *prompt, char **str, t_shell *shell)
{
	static t_line	*line = NULL;
	int				ret;

	if (-1 == line_init(prompt, &line))
		return (-1);
	ret = 1;
	raw_terminal_mode();
	while (ret == 1)
	{
		if (!line->ilen)
			ret = get_input(line);
		if (ret)
			ret = read_input(line, shell);
		else
			ret = 1;
		line_update(line, shell);
	}
	*str = line->str;
	default_terminal_mode();
	ft_putchar_fd('\n', 2);
	return (1);
}
