/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 09:08:47 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/14 02:40:03 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*ft_img_init(char *path_img, t_game *game)
{
	void	*img_ptr;

	img_ptr = mlx_xpm_file_to_image(game->mlx, path_img, \
	&game->win_width, &game->win_height);
	return (img_ptr);
}

void	ft_window_size(t_game *game)
{
	game->win_width = game->data.map.colunms * SPRITE_SIZE;
	game->win_height = (game->data.map.rows + 1) * SPRITE_SIZE;
}

void	ft_all_img_init(t_game *game)
{
	game->data.map.floor_img = ft_img_init(FLOOR, game);
	game->data.map.wall_img = ft_img_init(WALL, game);
	game->data.map.collet_img = ft_img_init(COLLECT, game);
	game->data.map.door_img = ft_img_init(DOOR_C, game);
	game->data.player.img = ft_img_init(PLAYER, game);
}

void	ft_put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * SPRITE_SIZE, \
	y * SPRITE_SIZE);
}

void	ft_map_drow(t_game *game)
{
	int			i;
	int			j;
	static int	p_flag = 0;
	static int	d_flag = 0;

	i = 0;
	while (i < game->data.map.rows + 1)
	{
		j = 0;
		while (game->data.map.mtx[i][j])
		{
			if (game->data.map.mtx[i][j] == '1')
				ft_put_image(game, game->data.map.wall_img, j, i);
			else if (game->data.map.mtx[i][j] == '0')
				ft_put_image(game, game->data.map.floor_img, j, i);
			else if (game->data.map.mtx[i][j] == 'C')
				ft_put_image(game, game->data.map.collet_img, j, i);
			else if (game->data.map.mtx[i][j] == 'E')
				ft_put_door(game, i, j, &d_flag);
			else if (game->data.map.mtx[i][j] == 'P')
				ft_put_player(game, i, j, &p_flag);
			j++;
		}
		i++;
	}
}
