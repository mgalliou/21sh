/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_do_word_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:06:35 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/21 16:33:36 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

void	key_do_word_right(t_line *line)
{
	int	ret;

	ret = 0;
	while (!ret && !ft_isblank((line->str[line->cpos])))
		ret = key_do_char_right(line, 1);
	while (!ret && ft_isblank((line->str[line->cpos])))
		ret = key_do_char_right(line, 1);
}
