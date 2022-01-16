/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:17:28 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/15 20:17:17 by lamorim          ###   ########.fr       */
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
	mlx_destroy_image(game->mlx, game->data.player.img_b);
	mlx_destroy_image(game->mlx, game->data.player.img_l);
	mlx_destroy_image(game->mlx, game->data.player.img_r);
	mlx_destroy_image(game->mlx, game->data.map.enemy_img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

int	ft_close_esc(int keycode, t_game *game)
{
	if (keycode == ESC || keycode == Q)
		ft_destroy_window(game);
	return (0);
}
