/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_cmdline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 13:29:07 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/22 16:16:23 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shell.h>

/*
**void			tokens_print(t_list *tokens)
**{
**	while (tokens)
**	{
**		ft_putnbr(((t_tok*)tokens->content)->type);
**		ft_putendl(((t_tok*)tokens->content)->s);
**		tokens = tokens->next;
**	}
**}
*/

int			cmdline_interpret(char *cmdline, t_shell *shell)
{
	t_list	*tokens;
	t_list	*cmds;

	if (!cmdline)
		return (!shell->exitcode ? 1 : shell->exitcode);
	tokens = NULL;
	cmds = NULL;
	if (-1 == cmdline_tokenize(&tokens, &cmdline, shell))
	{
		shell->exitcode = 1;
		if (!shell->isinteractive)
			exit(shell->exitcode);
	}
	else if (-1 == tokens_read(&cmds, tokens))
	{
		shell->exitcode = 1;
		if (!shell->isinteractive)
			exit(shell->exitcode);
	}
	else if (-1 == exec_cmds(cmds, shell))
		shell->exitcode = 1;
	ft_lstdel(&tokens, &tok_del);
	ft_lstdel(&cmds, &cmd_del);
	shell = shell_update(cmdline, shell);
	return (shell->exitcode);
}
