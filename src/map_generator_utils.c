/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:36:53 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/13 17:21:58 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_destroy_window(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	mlx_loop_end(game->mlx);
	ft_free_game(game);
	mlx_destroy_image(game->mlx, game->data.map.floor_img);
	mlx_destroy_image(game->mlx, game->data.map.wall_img);
	mlx_destroy_image(game->mlx, game->data.map.collet_img);
	mlx_destroy_image(game->mlx, game->data.map.door_img);
	mlx_destroy_image(game->mlx, game->data.player.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

int	ft_close_esc(int keycode, t_game *game)
{
	if (keycode == ESC)
		ft_destroy_window(game);
	return (0);
}

void	ft_put_door(t_game *game, int i, int j, int *flag)
{
	if (!*flag)
	{
		ft_put_image(game, game->data.map.door_img, j, i);
		game->door.x = j;
		game->door.y = i;
		(*flag)++;
	}
	else
	{
		game->data.map.mtx[i][j] = '0';
		ft_put_image(game, game->data.map.floor_img, j, i);
	}
}

void	ft_put_player(t_game *game, int i, int j, int *flag)
{
	if (!*flag)
	{
		ft_init_player(game, j, i);
		(*flag)++;
	}
	else
	{
		game->data.map.mtx[i][j] = '0';
		ft_put_image(game, game->data.map.floor_img, j, i);
	}
}