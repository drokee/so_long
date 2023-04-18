NAME = so_long

NAMEB = so_long_bonus

SRC = so_long.c errors.c graphics.c hooks.c utils.c position.c pathchecker.c hilper25line.c \
			desimg.c dataerror.c

SRCB = solong_bonus.c errors_bonus.c graphics_bonus.c hooks_bonus.c utils_bonus.c \
		position_bonus.c pathchecker_bonus.c hilper25line_bonus.c desimg_bonus.c \
		dataerror_bonus.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

LIBFT = ./libft/libft.a

PRINT = ./ft_printf/libftprintf.a

GNL = ./getnextline/get_next_line.a

GREEN ="\033[32m"
CYAN = "\033[36m"
ORANGE = "\033[33m"
PURPLE = "\033[35m"

all: $(NAME)

$(NAME): $(SRC) $(LIBFT) $(PRINT) $(GNL)
	@echo $(ORANGE)"Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(PRINT) $(GNL) -o $(NAME)> /dev/null 2>&1
	@echo $(GREEN)"compiled successfully!"

bonus:$(SRCB) $(LIBFT) $(PRINT) $(GNL)
	@echo $(ORANGE)"Compiling $(NAMEB)..."
	@$(CC) $(CFLAGS) $(SRCB) $(LIBFT) $(PRINT) $(GNL) -o $(NAMEB)> /dev/null 2>&1
	@echo $(GREEN)"compiled successfully!"

$(LIBFT):
	@echo $(ORANGE)"Building libft..."
	@make -C libft> /dev/null 2>&1

$(PRINT):
	@echo "Building ft_printf..."
	@make -C ft_printf> /dev/null 2>&1

$(GNL):
	@echo "Building get_next_line..."
	@make -C getnextline> /dev/null 2>&1

clean:
	@echo $(PURPLE)"Cleaning up..."
	@make -C ft_printf clean > /dev/null 2>&1
	@make -C getnextline clean > /dev/null 2>&1 
	@make -C libft clean > /dev/null 2>&1

fclean: clean
	@echo "Cleaning up all..."
	@rm -f $(NAME) $(NAMEB)> /dev/null 2>&1
	@make -C ft_printf fclean > /dev/null 2>&1
	@make -C getnextline fclean > /dev/null 2>&1
	@make -C libft fclean > /dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re
