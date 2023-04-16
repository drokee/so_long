NAME = so_long

SRC = so_long.c errors.c graphics.c hooks.c utils.c position.c pathchecker.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

LIBFT = ./libft/libft.a

PRINT = ./ft_printf/libftprintf.a

GNL = ./getnextline/get_next_line.a

all: $(NAME)

$(NAME): $(SRC) $(LIBFT) $(PRINT) $(GNL)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(PRINT) $(GNL) -o $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(PRINT):
	$(MAKE) -C ft_printf

$(GNL):
	$(MAKE) -C getnextline

clean:
	$(MAKE) -C ft_printf clean
	$(MAKE) -C getnextline clean
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ft_printf fclean
	$(MAKE) -C getnextline fclean
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
