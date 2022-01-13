/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:30:37 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/13 11:14:20 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include "libraries/minilibx-linux/mlx.h"
# include "libraries/libft/libft.h"

# define W 0x77
# define S 0x73
# define A 0x61
# define D 0x64
# define ESC 0xff1b

# define ERROR_1 "\e[1;91m \tError 01! \e[0m Invalid number of argumeets.\n"
# define ERROR_2 "\e[1;91m \tError 02! \e[0m Invalid map extension.\n"
# define ERROR_3 "\e[1;91m \tError 03! \e[0m Null read, nonexistent %s map.\n"
# define ERROR_4 "\e[1;91m \tError 04! \e[0m Invalid map composition.\
 Map is not a rectangle.\n"
# define ERROR_5 "\e[1;91m \tError 05! \e[0m Invalid map composition.\
 Missing mandatory item.\n"
# define ERROR_6 "\e[1;91m \tError 06! \e[0m Invalid map composition.\
 Ivalid char on the map.\n"
# define ERROR_7 "\e[1;91m \tError 07! \e[0m Invalid map composition.\
 Ivalid char on the map border.\n"

# define SPRITE_SIZE 64

# define FLOOR "./src/images/floor.xpm"
# define WALL "./src/images/wall_2.xpm"
# define DOOR_C "./src/images/close_door.xpm"
# define DOOR_O "./src/images/open_door.xpm"
# define COLLECT "./src/images/collectable.xpm"
# define PLAYER "./src/images/player_front.xpm"

typedef struct s_position {
	int	x;
	int	y;
}	t_position;

typedef struct s_player {
	t_position	position;
	void		*img;
}				t_player;

typedef struct s_map {
	int			fd;
	int			arg_c;
	char		*name;
	char		*str;
	char		**mtx;
	int			rows;
	int			colunms;
	void		*floor_img;
	void		*wall_img;
	void		*collet_img;
	void		*door_img;
}			t_map;

typedef struct s_data {
	t_map		map;
	t_player	player;
}			t_data;

typedef struct s_game {
	void		*mlx;
	void		*win;
	t_data		data;
	int			win_width;
	int			win_height;
	int			colletable;
	t_position	door;
	int			end_game;
	int			steps;
}				t_game;

int		ft_destroy_window(t_game *game);
int		ft_close_esc(int keycode, t_game *game);
void	ft_valid_nbr_arguments(int arg_c);
int		ft_valid_map_extension(t_game *game);
void	ft_read_map(t_game *game);
void	ft_mtxmap_generator(t_game *game);
void	ft_lines_cmp(t_game *game);
void	ft_check_map_itens(t_game *game);
void	ft_check_wrong_itens(t_game *game);
void	ft_check_border(t_game *game);
void	ft_window_size(t_game *game);
void	*ft_img_init(char *path_img, t_game *game);
void	ft_all_img_init(t_game *game);
void	ft_put_image(t_game *game, void *img, int x, int y);
void	ft_put_door(t_game *game, int i, int j, int *flag);
void	ft_put_player(t_game *game, int i, int j, int *flag);
void	ft_map_drow(t_game *game);
void	ft_init_player(t_game *game, int j, int i);
int		ft_move_player(int key, t_game *game);
void	ft_move_w(t_game *game, int *i, int *j);
void	ft_move_s(t_game *game, int *i, int *j);
void	ft_move_a(t_game *game, int *i, int *j);
void	ft_move_d(t_game *game, int *i, int *j);
void	ft_move(t_game *game, void (*f)(t_game *game, int *i, int *j), \
int *i, int *j);
void	ft_collet_count(t_game *game);
void	ft_open_door(t_game *game);
void	ft_game_init(t_game *game);
void	ft_end_game(t_game *game);
void	ft_free_game(t_game *game);

#endif
