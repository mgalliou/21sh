/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 16:01:58 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/21 13:12:30 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

void		redir_del(void *p, size_t size)
{
	t_redir	*redir;

	(void)size;
	redir = p;
	if (redir)
		ft_memdel((void*)&redir);
}

void		cmd_del(void *p, size_t size)
{
	t_cmd	*cmd;

	(void)size;
	cmd = p;
	if (cmd)
	{
		if (cmd->av)
			ft_memdel((void*)&cmd->av);
		if (cmd->redir)
			ft_lstdel(&cmd->redir, &redir_del);
		ft_memdel((void*)&cmd);
	}
}
