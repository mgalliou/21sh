/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_do_complete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 11:24:56 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/14 19:53:42 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

static int	look_into_binaries(int n, char **cmd, t_rb_node *binaries,
		t_line *line)
{
	if (binaries && cmd)
	{
		n += look_into_binaries(n, cmd, binaries->left, line);
		if (ft_strnequ(line->str, ((t_bin*)binaries->item)->name,
					ft_strclen(line->str, ' ')))
		{
			if (!*cmd)
				*cmd = ((t_bin*)binaries->item)->name;
			n++;
		}
		n += look_into_binaries(n, cmd, binaries->right, line);
	}
	return (n);
}

static int	get_possibility(char **aword, t_line *line, t_shell *shell)
{
	int		i;
	int		n;

	*aword = NULL;
	i = 0;
	n = 0;
	while (shell->builtins[i])
	{
		if (ft_strnequ(&line->str[line->wbeg], shell->builtins[i],
					line->cpos - line->wbeg))
		{
			if (!*aword)
				*aword = shell->builtins[i];
			++n;
		}
		++i;
	}
	if (!n)
		return (look_into_binaries(n, aword, shell->binaries, line));
	return (n);
}

void		key_do_complete(t_line *line, t_shell *shell)
{
	char	*word;

	if (line->str)
	{
		line->wbeg = line->cpos;
		while (line->wbeg && !ft_isblank(line->str[line->wbeg - 1]))
			--line->wbeg;
		if (ft_isprint(line->str[line->wbeg]) &&
				!ft_isblank(line->str[line->wbeg]))
		{
			if (get_possibility(&word, line, shell) && word)
				line_replace(word, line);
		}
	}
}
