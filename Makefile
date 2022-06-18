NAME	= simple

CC		=	gcc
CFLAGS	=	-Wall -Wextra -g #-Werror
MLX		=   -lmlx -lXext -lX11
# HEADER	= 	./src/includes/minirt.h

SRC		= calc_2.c \
	calc_3.c \
	calc.c \
	mirror.c \


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(<:%.c=%.o)

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	rm -rf $(NAME)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -lm -o $(NAME)

clean:
	rm -rf $(OBJ)
	rm -rf ./a.out

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
