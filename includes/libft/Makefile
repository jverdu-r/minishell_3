# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jverdu-r <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/24 17:52:10 by jverdu-r          #+#    #+#              #
#    Updated: 2023/06/17 11:49:42 by jverdu-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
		ft_memset.c ft_strchr.c ft_strncmp.c ft_strdup.c ft_strlcat.c ft_strlcpy.c \
		ft_strlen.c ft_strnstr.c ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_split.c	ft_itoa.c ft_strrchr.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strcmp.c

BONUSSRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		   ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		   ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS	= ${SRCS:.c=.o}

BONUSOBJS = ${BONUSSRCS:.c=.o}

NAME	= libft.a

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra 

.c.o:
		${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
		ar rc ${NAME} ${OBJS}

bonus:
		make SRCS="${SRCS} ${BONUSSRCS}"

all:	${NAME}

clean:
		${RM} ${OBJS} ${BONUSOBJS}

fclean: clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	clean re all bonus fclean
