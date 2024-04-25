NAME = ./so_long
CC = cc
CFLAGS = 
LIBRARY = libft/libft.a
LIBX = minilibx-linux/libmlx_Linux.a
RM = rm -rf 
SRC = src/main.c gnl/get_next_line.c gnl/get_next_line_utils.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(LIBRARY) :
	$(MAKE) -C libft

$(LIBX) :
	$(MAKE) -C minilibx-linux 

$(NAME) : $(OBJ) $(LIBRARY) $(LIBX)
	$(CC)  $(CFLAGS)  -Lminilibx-linux  -lmlx_Linux  $^ -o $@ -lX11 -lXext 

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)
	$(MAKE) -C libft clean
	$(MAKE) -C minilibx-linux clean

fclean :
	$(RM) $(NAME) $(OBJ)
	$(MAKE) -C libft fclean
	$(MAKE) -C minilibx-linux clean


re: fclean all

.PHONY: all clean fclean re 
