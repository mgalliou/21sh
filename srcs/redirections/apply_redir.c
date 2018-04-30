/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:58:57 by edhommee          #+#    #+#             */
/*   Updated: 2018/04/18 14:45:58 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirections.h"
#include <unistd.h>

static int	red_lessand(t_redir *red)
{
	if (!ft_strcmp(red->word, "-"))
	{
		close(red->in);
		return (0);
	}
	else if (ft_isnumber(red->word))
	{
		if (dup2(ft_atoi(red->word), red->in) >= 0)
			return (0);
		else
			return (redirection_error(red->word, -6));
	}
	return (redirection_error(red->word, -4));
}

static int	red_greatand(t_redir *red)
{
	if (!ft_strcmp(red->word, "-"))
	{
		close(red->in);
		return (0);
	}
	else if (ft_isnumber(red->word))
	{
		if (dup2(ft_atoi(red->word), red->in) >= 0)
			return (0);
		else
			return (redirection_error(red->word, -6));
	}
	return (red_great(red));
}

static int	one_redir(t_redir *red)
{
	int						i;
	static t_tab_f const	functs[] = {
		{LESS, &red_less},
		{GREAT, &red_great},
		{DLESS, &red_dless},
		{DGREAT, &red_dgreat},
		{LESSAND, &red_lessand},
		{GREATAND, &red_greatand},
		{LESSGREAT, &red_lessgreat},
		{DLESSDASH, &red_dless},
		{CLOBBER, &red_great},
		{SEMI, NULL}
	};

	i = 0;
	while (functs[i].f != NULL)
	{
		if (functs[i].type == red->type)
			return ((functs[i].f)(red));
		i++;
	}
	return (-1);
}

int			apply_redir(t_list *redir)
{
	t_list	*tmp;

	tmp = redir;
	while (tmp)
	{
		if ((one_redir((t_redir*)tmp->content)) < 0)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

void		reverse_redir(t_list *redir)
{
	t_list	*tmp;

	tmp = redir;
	while (tmp)
	{
		if (((t_redir*)tmp->content)->rec >= 0)
		{
			dup2(((t_redir*)tmp->content)->rec, ((t_redir*)tmp->content)->in);
			close(((t_redir*)tmp->content)->rec);
		}
		tmp = tmp->next;
	}
}
