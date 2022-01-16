/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 09:08:47 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/15 15:21:30 by lamorim          ###   ########.fr       */
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
	game->data.player.img_b = ft_img_init(PLAYER_B, game);
	game->data.player.img_l = ft_img_init(PLAYER_L, game);
	game->data.player.img_r = ft_img_init(PLAYER_R, game);
	game->data.map.enemy_img = ft_img_init(ENEMY, game);
}

void	ft_put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * SPRITE_SIZE, \
	y * SPRITE_SIZE);
}

void	ft_map_draw(t_game *game)
{
	int			i;
	int			j;

	i = 0;
	while (i < game->data.map.rows + 1)
	{
		j = 0;
		while (game->data.map.mtx[i][j])
		{
			ft_help_draw(game, i, j);
			j++;
		}
		i++;
	}
}
