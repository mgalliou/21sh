/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 17:10:41 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/18 21:09:39 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int				read_input(t_line *line, t_shell *shell)
{
	line->stop = 0;
	while (line->input[line->i] && !line->stop)
		line->i += do_input(&line->input[line->i], line, shell);
	if (!line->input[line->i] && !line->stop)
	{
		line->i = 0;
		ft_strclr(line->input);
		line->ilen = 0;
		return (1);
	}
	line->cpos = 0;
	return (0);
}
