NAME = pipex
NAME_BONUS = pipex_bonus

cc = gcc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT = libft/libft.a

SRCS = pipex.c
SRCS_BONUS = pipex_bonus.c pipex_utils_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS) $(LIBFT)
	$(cc) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
	$(cc) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIBFT)

%.o: %.c
	$(cc) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all bonus clean fclean re
