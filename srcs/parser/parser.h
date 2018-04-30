/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 12:03:54 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/17 17:42:20 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <shell.h>
# include <unistd.h>

int					tok_isoftype(t_list *token, t_tok_type type);
int					tok_isseparator(t_list *token);
void				redir_del(void *p, size_t size);

t_cmd				*cmd_new(t_list *tokens);
t_redir				*get_redir(t_list *prev, t_list *red);
void				del_token(void *tok, size_t size);
int					create_pipes(t_list *lst, t_shell *shell);

#endif
