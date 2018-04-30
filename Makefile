# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgalliou <mgalliou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/28 13:13:07 by mgalliou          #+#    #+#              #
#    Updated: 2018/04/23 15:16:52 by edhommee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#    COLOR CODES                                                               #
# **************************************************************************** #

ESC			=	\033
CBLACK		=	$(ESC)[30;1m
CRED		=	$(ESC)[31;1m
CGREEN		=	$(ESC)[32;1m
CYELLOW		=	$(ESC)[33;1m
CBLUE		=	$(ESC)[34;1m
CMAGENTA	=	$(ESC)[35;1m
CCYAN		=	$(ESC)[36;1m
CWHITE		=	$(ESC)[37;1m
CRESET		=	$(ESC)[m

# **************************************************************************** #

# **************************************************************************** #
#	NAME / UTILITY / FLAGS / LIBS
# **************************************************************************** #

NAME		=	21sh
RM			= 	rm -rf
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS	=	$(foreach dir, $(INC_DIR), -I$(dir))
LDFLAGS		=	-L$(LIB_DIR)
RM			= 	rm -rf
LDLIBS		=	-lft -ltermcap
LIB_NAME	=	libft.a
LIB_DIR		=	libft
LIB			=	$(addprefix $(LIB_DIR)/,$(LIB_NAME))

# **************************************************************************** #
#	INCLUDES
# **************************************************************************** #

INC_DIR		=	includes libft/includes
INC			=	$($(INC_DIR)/*.h)

# **************************************************************************** #
#	SOURCES
# **************************************************************************** #

# 		BUILTINS	********************************************************** #

SRC_BI_DIR	=	builtins
SRC_BI_NAME	=	\
				bi_cd.c \
				bi_echo.c \
				bi_env.c \
				bi_exit.c \
				bi_setenv.c \
				bi_unsetenv.c \
				bi_plec.c
SRC_BI_NAME	:=	$(addprefix $(SRC_BI_DIR)/, $(SRC_BI_NAME))

# 		LINE_EDITING	****************************************************** #

SRC_LE_DIR	=	line_editing
SRC_LE_NAME =	\
				cmdline_insert.c \
				default_terminal_mode.c \
				do_input.c \
				get_and_edit_line.c \
				history_prev.c \
				history_next.c \
				istermcap.c \
				isinput.c \
				isvalidchar.c \
				key_do_backspace.c \
				key_do_char_left.c \
				key_do_char_right.c \
				key_do_clear.c \
				key_do_complete.c \
				key_do_ctrl_c.c \
				key_do_ctrl_d.c \
				key_do_delete.c \
				key_do_end.c \
				key_do_home.c \
				key_do_line_down.c \
				key_do_line_up.c \
				key_do_select_left.c \
				key_do_select_right.c \
				key_do_word_left.c \
				key_do_word_right.c \
				key_do_copy.c \
				key_do_past.c \
				key_do_return.c \
				line_init.c \
				line_putchar.c \
				line_putstr.c \
				line_update.c \
				line_replace.c \
				line_reprint.c \
				line_reset_selection.c \
				move_cur_left.c \
				move_cur_right.c \
				raw_terminal_mode.c \
				read_input.c \
				tputc.c
SRC_LE_NAME	:=	$(addprefix $(SRC_LE_DIR)/, $(SRC_LE_NAME))

# 		LEXER	************************************************************** #

SRC_LEX_DIR		=	lexer
SRC_LEX_NAME	=	\
					isopechar.c \
					isquotechar.c \
					isbegofopechar.c \
					isquoted.c \
					do_word_expansions.c \
					do_heredoc.c\
					start_quoting.c \
					token_append_char.c \
					token_delimite.c \
					curr_word_isope.c \
					check_rules.c \
					cmdline_tokenize.c
SRC_LEX_NAME	:=	$(addprefix $(SRC_LEX_DIR)/, $(SRC_LEX_NAME))

# 		PARSER	************************************************************** #

SRC_PAR_DIR		=	parser
SRC_PAR_NAME	=	\
					cmd_new.c \
					tokens_read.c \
					tok_isoftype.c \
					tok_isseparator.c \
					get_redir.c
SRC_PAR_NAME	:=	$(addprefix $(SRC_PAR_DIR)/, $(SRC_PAR_NAME))

# 		REDIRECTIONS	****************************************************** #

SRC_RED_DIR		=	redirections
SRC_RED_NAME	=	\
					apply_redir.c \
					redirections.c \
					utils_redirection.c \
					ft_getstat.c
SRC_RED_NAME	:=	$(addprefix $(SRC_RED_DIR)/, $(SRC_RED_NAME))

# 		EXEC    ************************************************************** #

SRC_EX_DIR		=	exec
SRC_EX_NAME	=	\
					exec_cmds.c \
					exec_binary.c \
					exec_builtin.c
SRC_EX_NAME	:=	$(addprefix $(SRC_EX_DIR)/, $(SRC_EX_NAME))


# 		CORE	************************************************************** #

SRC_DIR		=	srcs
SRC_NAME	=	\
				bindel.c \
				cmd_del.c \
				cmdline_interpret.c \
				get_binaries.c \
				get_cmdline.c \
				get_envpathentry.c \
				handle_exitstatus.c \
				isdotdot.c \
				main.c \
				shell_init.c \
				shell_update.c \
				signals_handle.c \
				tok_del.c \
				simplify_path.c
SRC_NAME	+=	$(SRC_BI_NAME) $(SRC_LE_NAME) $(SRC_LEX_NAME) $(SRC_PAR_NAME) \
				$(SRC_RED_NAME) $(SRC_EX_NAME)
SRC			=	$(addprefix $(SRC_DIR)/,$(SRC_NAME))


# **************************************************************************** #
#	OBJS
# **************************************************************************** #

OBJ_NAME	=	$(SRC_NAME:.c=.o)
OBJ_DIR		=	./objs
OBJ			=	$(addprefix $(OBJ_DIR)/,$(OBJ_NAME))

# **************************************************************************** #
#	HEADER
# **************************************************************************** #

HEAD		=	[ $(NAME) ]
CHEAD		=	"$(CYELLOW)$(HEAD)$(CRESET)"

define print_info
    @printf "%b %s\n" $(CHEAD) $(1)
endef

# **************************************************************************** #
#	RULES
# **************************************************************************** #

all : $(NAME)

$(NAME): $(OBJ)
	$(call print_info,"all objects created with $(CFLAGS)")
	@$(CC) $(LDFLAGS) $(OBJ) $(LDLIBS) -o $@ #-fsanitize=address
	$(call print_info,"binary created")

$(LIB):
	@make -C $(LIB_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC) $(LIB)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ #-fsanitize=address
	$(call print_info,"$(<:srcs/%=%) compiled")

clean :
	@$(RM) $(OBJ_DIR)
	$(call print_info,"all objects deleted")
	@make $@ -C $(LIB_DIR)

fclean : clean
	@$(RM) $(NAME)
	$(call print_info,"binary deleted")
	@make $@ -C $(LIB_DIR)

re : fclean all

norminette :
	@make $@ -C $(LIB_DIR)
	@$@ $(SRC_DIR) $(INC_DIR)

.PHONY: all clean fclean re norminette
