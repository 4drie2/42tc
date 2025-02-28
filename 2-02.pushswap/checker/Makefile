# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/28 14:52:58 by abidaux           #+#    #+#              #
#    Updated: 2025/02/28 15:13:30 by abidaux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror
PUSH_SWAP_ARCHIVE = ../program/push_swap.a

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

all : $(NAME)

$(NAME) : $(OBJS) $(PUSH_SWAP_ARCHIVE)
	$(CC) $^ -o $(NAME)
	cp $(NAME) ../program

$(PUSH_SWAP_ARCHIVE) :
	cd ../program && make

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
