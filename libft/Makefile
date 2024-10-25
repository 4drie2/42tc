NAME      := libft.a
CFLAGS     := -Wall -Wextra -Werror

SRC      := ft_isalpha.c \
			 ft_isalnum.c \
			 ft_isdigit.c \
			 ft_isascii.c \
			 ft_isprint.c \
			 ft_strlen.c \
			 ft_memset.c \
			 ft_bzero.c \
			 ft_memcpy.c \
			 ft_memmove.c \
			 ft_strlcpy.c \
			 ft_strlcat.c \
			 ft_toupper.c \
			 ft_tolower.c \
			 ft_strchr.c \
			 ft_strrchr.c \
			 ft_atoi.c \
			 ft_memchr.c \
			 ft_memcmp.c \
			 ft_strncmp.c \
			 ft_strnstr.c \
			 ft_calloc.c \
			 ft_strdup.c \
			 ft_substr.c \
			 ft_strjoin.c \
			 ft_strtrim.c \

OBJ      := $(SRC:.c=.o)
ARFLAGS   := rcs
RM		    := rm -f

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
			$(AR) $(ARFLAGS) $(NAME) $(OBJ)

all:		$(NAME)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
