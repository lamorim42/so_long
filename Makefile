
CC = clang
CC_FALGS = -Wall -Wextra -Werror -g3
OBJ = main.c
NAME = so_long

%.o: %.c
	$(CC) $(CC_FLAGS) -lmlx -lXext -lX11 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CC_FLAGS) $(OBJ) -lmlx -lXext -lX11 -o $(NAME)

