NAME = ./so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBRARY = libft/libft.a
RM = rm -rf 
SRC = src/main.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(LIBRARY) :
	$(MAKE) -C libft

$(NAME) : $(OBJ) $(LIBRARY)
	$(CC) $(CFLAGS) $^ -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)
	$(MAKE) -C libft clean

fclean :
	$(RM) $(NAME) $(OBJ)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
