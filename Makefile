.PHONY: all clean fclean make-libft re

NAME = so_long

OBJECTS = $(SRCS:.c=.o)

SRCS := so_long.c so_long_utils.c verify_map.c \
load_png.c make_map.c flood_fill.c \

all: make-libft $(NAME)

make-libft:
	@bash -c "make -s -C libft"

$(NAME): $(OBJECTS)
	@cc $(OBJECTS) libft/libft.a MLX42/libmlx42.a -I include -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" -o $(NAME)

$(OBJECTS): $(SRCS)
	@cc -c $^ -Wall -Wextra -Werror

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
