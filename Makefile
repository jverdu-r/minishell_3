# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jorge <jorge@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/24 15:20:41 by jverdu-r          #+#    #+#              #
#    Updated: 2024/06/06 09:14:42 by jorge            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

LIBFT	=	includes/libft/

CC		=	gcc

LIBFT_A	=	$(addprefix $(LIBFT), libft.a) 

INCLUDE	=	includes -I $(READ)/include

CFLAGS	=	-Wall -Werror -Wextra -g3 -I$(INCLUDE) -fsanitize=address  -ggdb

RM		=	rm -f

GNL = get_next_line.c get_next_line_utils.c
GNLPATH = $(addprefix ./includes/GetNextLine/,$(GNL))

SRCS	=	sources/main.c \
			sources/utils/signals.c \
			sources/utils/signals_two.c \
			sources/utils/minishell_loop.c \
			sources/utils/utils.c \
			sources/utils/utils_two.c \
			sources/utils/utils_three.c \
			sources/utils/parse_envp.c \
			sources/lexer/lexer_utils_one.c \
			sources/lexer/lexer_utils_two.c \
			sources/lexer/token_handler.c \
			sources/lexer/token_reader.c \
			sources/lexer/token_utils.c \
			sources/parser/command_utils.c \
			sources/parser/redir_utils.c \
			sources/parser/parser.c \
			sources/parser/parser_utils.c \
			sources/parser/handle_redirs.c \
			sources/parser/handle_redirs_2.c \
			sources/error/errors.c \
			sources/expander/expander_one.c \
			sources/expander/expander_utils_one.c \
			sources/expander/expander_utils_two.c \
			sources/built-ins/echo.c \
			sources/executor/executor.c \
			sources/executor/executor_2.c \
			sources/executor/executor_utils.c \
			sources/built-ins/pwd.c \
			sources/built-ins/env.c \
			sources/built-ins/export.c \
			sources/built-ins/export_utils.c \
			sources/built-ins/unset.c \
			sources/built-ins/cd.c \
			sources/built-ins/here_doc.c \
			sources/built-ins/here_doc_2.c \
			sources/built-ins/exit.c \

OBJS	=	$(SRCS:%.c=%.o)
GNLOBJ 	= 	$(GNLPATH:.c=.o)

#READ	=  	/System/Volumes/Data/Users/${USER}/.brew/Cellar/readline/8.2.1
#READ	=  	/System/Volumes/Data/Users/jverdu-r/.brew/Cellar/readline/8.2.1
READ	=  	/usr/local/Cellar/readline/8.2.10

all:		$(NAME)

$(NAME):	$(OBJS) $(GNLOBJ) $(LIBFT_A)
			@$(CC) $(CFLAGS) $(OBJS) $(GNLOBJ) -L$(LIBFT) -lft  -lreadline -L $(READ)/lib -o $(NAME)
			@echo "Linked into excutable \033[0;32mminishell\033[0m."

$(LIBFT_A):	
			@$(MAKE) bonus -s -C $(LIBFT)
			@echo "compiled $(LIBFT_A)."
.c.o:		
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
			@echo "Compiling... $<."

localclean:		
			@$(RM) $(OBJS)
			@echo "Removed object files."

clean:		localclean
			@$(MAKE) clean -s -C $(LIBFT)
			@echo "Clean libft."

fclean:		localclean
			@$(MAKE) fclean -s -C $(LIBFT)
			@echo "Full clean libft."
			@$(RM) $(GNLOBJ)
			@$(RM) $(NAME)
			@echo "Removed excutable file."

re:			fclean all

.PHONY:		all clean fclean re
