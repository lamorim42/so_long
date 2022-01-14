
SRC_PATH = src/
LIBFT_PATH = libraries/libft/
MLX_PATH = libraries/minilibx-linux

CC = clang
CFLAGS = -g3 -Wall -Wextra -Werror
MLXFLAGS = -L $(MLX_PATH) -lmlx -lXext -lX11
LIBFTFLAGS = -L $(LIBFT_PATH) -lft
SANIT = -fsanitize=address

SRC = so_long.c \
	$(SRC_PATH)/map_validation.c \
	$(SRC_PATH)/map_validation_utils.c \
	$(SRC_PATH)/read_map.c \
	$(SRC_PATH)/map_generator.c \
	$(SRC_PATH)/map_generator_utils.c \
	$(SRC_PATH)/move_player.c \
	$(SRC_PATH)/move_player_utils.c \
	$(SRC_PATH)/game_init.c \
	$(SRC_PATH)/game_manager.c \

OBJ = $(SRC:%.c=%.o)
NAME = so_long

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	make all -C $(LIBFT_PATH)
	make all -C $(MLX_PATH)
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) $(LIBFTFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFT_PATH)
	make clean -C $(MLX_PATH)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

git: fclean
	git status
	git add .
	git status
	git commit -m "Mandatory part ok!"

push:
	git push

test:
	valgrind --leak-check=full -s ./so_long maps/map_1.ber

.PHONY: all clean fclean re git push test
