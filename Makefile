
SRC_PATH = src/
SRC_PATH_BONUS = src_bonus/
LIBFT_PATH = libraries/libft/
MLX_PATH = libraries/minilibx-linux

CC = gcc
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
	$(SRC_PATH)/close_game.c \

SRC_BONUS = so_long.c \
	$(SRC_PATH_BONUS)/map_validation_bonus.c \
	$(SRC_PATH_BONUS)/map_validation_utils_bonus.c \
	$(SRC_PATH_BONUS)/read_map_bonus.c \
	$(SRC_PATH_BONUS)/map_generator_bonus.c \
	$(SRC_PATH_BONUS)/map_generator_utils_bonus.c \
	$(SRC_PATH_BONUS)/move_player_bonus.c \
	$(SRC_PATH_BONUS)/move_player_utils_bonus.c \
	$(SRC_PATH_BONUS)/game_init_bonus.c \
	$(SRC_PATH_BONUS)/game_manager_bonus.c \
	$(SRC_PATH_BONUS)/close_game_bonus.c \
	$(SRC_PATH_BONUS)/bonus_utils.c

OBJ = $(SRC:%.c=%.o)
OBJ_BONUS = $(SRC_BONUS:%.c=%.o)
NAME = so_long

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	make all -C $(LIBFT_PATH)
	make all -C $(MLX_PATH)
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) $(LIBFTFLAGS) -o $(NAME)

bonus: $(OBJ_BONUS)
	make all -C $(LIBFT_PATH)
	make all -C $(MLX_PATH)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(MLXFLAGS) $(LIBFTFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_BONUS)
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
	git commit -m "Bonus update."

push:
	git push

test: re
	valgrind --leak-check=full -s ./so_long maps/map_1.ber

norma:
	norminette so_long.c so_long.h src/

.PHONY: all clean fclean re git push test norminette
