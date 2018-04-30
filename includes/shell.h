/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 11:49:56 by mgalliou          #+#    #+#             */
/*   Updated: 2018/04/22 17:39:39 by mgalliou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <libft.h>
# include <termios.h>

# define ENV_OPTIONS "i"

# define MAX_HISTORY_LEN 100

# define SHELLNAME	"21sh"
# define EMNOMEM	"memory exhausted"
# define EMLOOP		"too many levels of symbolic links"
# define EMISDIR	"is a directory"
# define EMNOCMD	"command not found"
# define EMNOENT	"no such file or directory"
# define EMACCES	"permission denied"
# define EMNOTDIR	"not a directory"
# define EMNOENV	"not set"

# define EMNONUMARG	"numeric argument required"
# define EMTOMNYARG	"too many arguments"
# define EMTOFEWARG	"too few arguments"
# define EMVNMGWL	"variable name must begin with letter"
# define EMWRGVAR	"variable name must contain alphanumeric characters"

typedef struct		s_bin
{
	char			*name;
	char			*path;
}					t_bin;

/*
**	ASSIGMENT_WORD,
**	NAME,
*/

typedef enum		e_tok_type
{
	NEWLINE,
	SEMI,
	AND_IF,
	OR_IF,
	LESS,
	GREAT,
	DLESS,
	DGREAT,
	LESSAND,
	GREATAND,
	LESSGREAT,
	DLESSDASH,
	CLOBBER,
	PIPE,
	WORD,
	WORD_REDIR,
	IO_NUMBER
}					t_tok_type;

typedef struct		s_redir
{
	int				in;
	int				rec;
	t_tok_type		type;
	char			*word;
}					t_redir;

typedef struct		s_cmd
{
	char			**av;
	t_list			*redir;
	t_tok_type		sep;
}					t_cmd;

typedef struct		s_tok
{
	char			*s;
	int				b;
	int				e;
	t_tok_type		type;
}					t_tok;

typedef struct		s_shell
{
	int				ac;
	char			**av;
	int				isinteractive;
	struct termios	old_tattr;
	char			**builtins;
	char			*envpath;
	t_rb_node		*binaries;
	int				exitcode;
	char			*prompt;
	char			*lastcmdline;
	char			**history;
	int				historylen;
}					t_shell;

int					g_pid;

/*
**   LINE EDITING   ********************************************************** /
*/

void				default_terminal_mode();
int					get_and_edit_line(char *prompt, char **str, t_shell *shell);
void				raw_terminal_mode();

/*
**   REDIR   ***************************************************************** /
*/

int					apply_redir(t_list *redir);
void				reverse_redir(t_list *redir);
int					is_redirection(t_tok *tok);

/*
**   LEXER   ***************************************************************** /
*/

int					cmdline_tokenize(t_list **atokens, char **as,
						t_shell *shell);

/*
**   PARCER   **************************************************************** /
*/

int					tokens_read(t_list **acmd, t_list *tokens);

/*
**   EXEC   ****************************************************************** /
*/

int					exec_cmds(t_list *cmds, t_shell *shell);

/*
**   BUILTINS   ************************************************************** /
*/

char				*simplify_path(char *path);
int					bi_cd(char **av);
int					bi_echo(char **av);
int					bi_env(char **av);
int					bi_exit(char **av, int exitcode);
int					bi_plec(char **av, int exitcode);
int					bi_setenv(char **av);
int					bi_unsetenv(char **av);
int					isdotdot(char *path);

/*
**   CORE   ****************************************************************** /
*/

char				*get_envpathentry(char *cmd, char *envivar);
int					get_cmdline(char *prompt, char **acmdline, t_shell *shell);
int					cmdline_interpret(char *cmdline, t_shell *shell);
void				cmd_del(void *p, size_t size);
t_rb_node			*get_binaries(char *envpath);
t_shell				*shell_init(int ac, char **av);
t_shell				*shell_update(char *lastcmdline, t_shell *shell);
void				bindel(void *acmd);
void				handle_signal(int sig);
int					handle_exitstatus(char *cmd, int pid, int status);
void				tok_del(void *p, size_t size);
void				signals_handle(void);
void				signals_ignore(void);

#endif
