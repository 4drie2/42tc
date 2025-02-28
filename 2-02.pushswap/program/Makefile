# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abidaux <abidaux@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/27 19:47:46 by abidaux           #+#    #+#              #
#    Updated: 2025/02/28 15:14:14 by abidaux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
ARCHIVE = push_swap.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
MAKE_LIB = ar -rcs

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(ARCHIVE)
	$(CC) $< -o $@

$(ARCHIVE) : $(OBJS)
	$(MAKE_LIB) $(ARCHIVE) $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus :
	cd ../checker && make

clean :
	rm -f $(OBJS)
	cd ../checker && make clean

fclean : clean
	rm -f $(NAME) $(ARCHIVE)
	cd ../checker && make fclean

re : fclean all

.PHONY: all clean fclean re bonus

