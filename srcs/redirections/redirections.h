/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:17:20 by edhommee          #+#    #+#             */
/*   Updated: 2018/04/13 14:59:15 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTIONS_H
# define REDIRECTIONS_H

# include <shell.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_tab_f
{
	t_tok_type		type;
	int				(*f)(t_redir*);
}					t_tab_f;

int					ft_isnumber(char *src);
int					is_redirection(t_tok *tok);
int					redirection_error(char *word, int i);
int					get_stmode(char *pathfile, char opt, int fn);

int					dup_fd(int newfd, int oldfd);
int					open_file(char *file, int oldfd, int flags, int mode);
int					do_heredoc(int fd, char *eoi, t_shell *shell);

int					red_less(t_redir *red);
int					red_great(t_redir *red);
int					red_dless(t_redir *red);
int					red_dgreat(t_redir *red);
int					red_lessgreat(t_redir *red);

#endif
