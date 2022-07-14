# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 14:58:05 by euyi              #+#    #+#              #
#    Updated: 2022/07/11 18:06:32 by euyi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

SRC = app/main.c	app/main_utils.c	app/main_utils_2.c \
	app/main_utils_3.c	app/main_utils_4.c	app/main_utils_5.c	\
	app/commands.c	app/algo.c	assets/ft_atoi.c

BSRC = bonus/app/main.c	bonus/app/commands.c	bonus/assets/ft_calloc.c	\
	bonus/assets/ft_memset.c	bonus/assets/ft_strncmp.c	bonus/app/main_utils.c	\
	app/main_utils.c	app/main_utils_2.c \
	app/main_utils_3.c	app/main_utils_4.c	app/main_utils_5.c	\
	app/commands.c	app/algo.c	assets/ft_atoi.c
	

OBJ = $(subst .c,.o,$(SRC))

BOBJ = $(subst .c,.o,$(BSRC))

CC ?= cc

CFLAGS = -Wall	-Werror	-Wextra

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

bonus: $(BONUS)

$(BONUS):	$(BOBJ)
	$(CC) $(CFLAGS) -o $(BONUS)	$(BOBJ)

clean:
	/bin/rm -f $(OBJ)	$(BOBJ)

fclean: clean
	/bin/rm -f $(NAME)	$(BONUS)

re: fclean all

.PHONY:	all	clean	fclean	re	bonus
