.PHONY: all clean fclean re

NAME = libft.a
OBJECTS = $(SRCS:.c=.o)

SRCS := ft_isalpha.c ft_isdigit.c \
ft_isalnum.c ft_isascii.c ft_linelen.c \
ft_isprint.c ft_strlen.c ft_memset.c \
ft_bzero.c ft_memcpy.c ft_memmove.c \
ft_strlcpy.c ft_strlcat.c ft_toupper.c \
ft_tolower.c ft_strchr.c ft_strrchr.c \
ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strstr.c \
ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
ft_itoa.c ft_strmapi.c ft_striteri.c ft_putendl.c \
ft_printf.c ft_putstuff.c ft_putmorestuff.c \
get_next_line.c get_next_line_utils.c \
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
ft_lstclear.c ft_lstiter.c ft_lstmap.c

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar -rc $(NAME) $(OBJECTS)

$(OBJECTS): $(SRCS)
	@cc -c $^ -Wall -Wextra -Werror -D BUFFER_SIZE=42

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
