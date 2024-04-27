NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBRARY = libft/libft.a
LIBX = minilibx-linux/libmlx_Linux.a
RM = rm -rf 
SRC = src/main.c src/chek_map_component.c src/validate_map.c src/generate_map.c \
      src/init_game.c src/generate_window.c src/get_image.c src/generate_map_helper.c \
      src/move_player.c src/move_player_helper.c src/animate_component.c src/destroy_game.c \
      gnl/get_next_line.c gnl/get_next_line_utils.c ft_printf/ft_print_number_format.c \
      ft_printf/ft_print_string_format.c ft_printf/ft_printf.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBRARY):
	$(MAKE) -C libft

$(LIBX):
	$(MAKE) -C minilibx-linux 

$(NAME): $(OBJ) $(LIBRARY) $(LIBX)
	$(CC) $(CFLAGS) -o $@ $^ -Lminilibx-linux -lmlx_Linux -lX11 -lXext

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C libft clean
	$(MAKE) -C minilibx-linux clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.SECONDARY: $(OBJ)
.PHONY: all clean fclean re
