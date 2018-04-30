/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:38:26 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/17 17:39:38 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <shell.h>

int					exec_binary(char **cmdav, t_rb_node *pathcmd);
int					exec_builtin(char **cmdav, t_shell *shell);
void				cmd_del(void *p, size_t size);

#endif
