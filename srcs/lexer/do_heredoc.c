/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 12:02:12 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/14 18:30:20 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>
#include <libft.h>

char		*add_line_to_heredoc(char *line, char *hdoc)
{
	char	*tmp;

	if (line)
	{
		if (!hdoc)
			tmp = ft_strdup(line);
		else
		{
			tmp = ft_strcjoin(hdoc, line, '\n');
			ft_strdel(&hdoc);
		}
		hdoc = tmp;
	}
	return (hdoc);
}

int			do_heredoc(char **aeoi, t_shell *shell)
{
	char	*line;
	char	*hdoc;
	int		stop;

	stop = 0;
	hdoc = NULL;
	while (!stop)
	{
		if ((1 != get_cmdline("heredoc> ", &line, shell)))
			return (-1);
		if (line && *aeoi && !ft_strequ(line, *aeoi))
			hdoc = add_line_to_heredoc(line, hdoc);
		else
			stop = 1;
		ft_strdel(&line);
	}
	ft_strdel(aeoi);
	*aeoi = hdoc;
	return (0);
}
