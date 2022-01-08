
SRC_PATH = src/
LIBFT_PATH = libft/

CC = clang
C_FALGS = -g -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -lXext -lX11
LIBFT_FLAGS = -L libft/ -lft
SANIT = -fsanitize=address

SRC = main.c $(SRC_PATH)/map_validation.c $(SRC_PATH)/map_validation_utils.c \
	$(SRC_PATH)/read_map.c
OBJ = $(SRC:%.c=%.o)
NAME = so_long

%.o: %.c
	$(CC) $(C_FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	make all -C $(LIBFT_PATH)
	$(CC) $(C_FLAGS) $(OBJ) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFT_PATH)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

git:
	git status
	git add .
	git status
	git commit -m "create read_map.c"

push:
	git push

.PHONY: all clean fclean re git push
