# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 11:53:47 by blefebvr          #+#    #+#              #
#    Updated: 2022/10/21 16:14:28 by blefebvr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compiler
CC = gcc

# flags
CFLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g

# artifacts
NAME = push_swap

# source files
SRCS := push.c \
	list_utils.c\
	swap.c \
	rotate.c \
	rev_rotate.c \
	push_swap.c \
	args_utils.c

# bonus source files

# object files
OBJS := ${SRCS:.c=.o}

# bonus object files

# lib folders
DIRPRINTF = Printf

# libraries
LIBPUSHSWAP = push_swap.h
LIBFTPRINTF = Printf/libftprintf.a

RM	= rm -rf

# rules
all: ${NAME}

${NAME}: ${OBJS}
	$(MAKE) -C ${DIRPRINTF}
	${CC} ${CFLAGS} ${OBJS} ${LIBFTPRINTF} ${LIBPUSHSWAP} -o $@

%.o: %.c
	${CC} ${CFLAGS} ${DEBUG_FLAGS} -o $(<:.c=.o) -c $<

clean:
	${RM} ${OBJS}

fclean: clean
	@$(MAKE) fclean -C ${DIRPRINTF}
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
