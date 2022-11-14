# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 11:53:47 by blefebvr          #+#    #+#              #
#    Updated: 2022/11/13 16:29:14 by blefebvr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compiler
CC = gcc

# flags
CFLAGS = -g -Wall -Wextra -Werror

# artifacts
NAME = push_swap

# source files
SRCS := push.c \
	list_utils.c\
	swap.c \
	rotate.c \
	rev_rotate.c \
	push_swap.c \
	parsing.c \
	algo.c \
	algo_utils.c

# bonus source files

# object files
OBJS := ${SRCS:.c=.o}

# bonus object files

# lib folders
#DIRPRINTF = Printf

# libraries
LIBPUSHSWAP = push_swap.h
#LIBFTPRINTF = Printf/libftprintf.a

RM	= rm -rf

# rules
all: ${NAME}

${NAME}: ${OBJS} push_swap.h
#	$(MAKE) -C ${DIRPRINTF}
	${CC} ${CFLAGS} ${OBJS} ${LIBPUSHSWAP} -o $@

%.o: %.c
	${CC} ${CFLAGS} -o $(<:.c=.o) -c $<

clean:
	${RM} ${OBJS}

fclean: clean
#	@$(MAKE) fclean -C ${DIRPRINTF}
	${RM} ${NAME}

re: fclean all

test2:	$(NAME)	
	$(eval ARG = $(shell shuf -i 0-100 -n 2))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test3:	$(NAME)	
	$(eval ARG = $(shell shuf -i 0-100 -n 3))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test5:	$(NAME)	
	$(eval ARG = $(shell shuf -i 0-5000 -n 5))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test100:$(NAME)	
	$(eval ARG = $(shell shuf -i 0-5000 -n 100))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test500:$(NAME)	
	$(eval ARG = $(shell shuf -i 0-5000 -n 500))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test1000:$(NAME)	
	$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

.PHONY: all clean fclean re
