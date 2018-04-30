/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_do_word_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:06:37 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/21 16:32:41 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

void	key_do_word_left(t_line *line)
{
	int	ret;

	ret = 0;
	while (!ret && line->cpos && ft_isblank((line->str[line->cpos - 1])))
		ret = key_do_char_left(line, 1);
	while (!ret && line->cpos && !ft_isblank((line->str[line->cpos - 1])))
		ret = key_do_char_left(line, 1);
}
