/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 00:16:31 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/14 20:44:33 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_collet_count(t_game *game)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (game->data.map.str[i])
	{
		if (game->data.map.str[i] == 'C')
			flag++;
		i++;
	}
	game->colletable = flag;
}

void	ft_open_door(t_game *game)
{
	mlx_destroy_image(game->mlx, game->data.map.door_img);
	game->data.map.door_img = ft_img_init(DOOR_O, game);
	ft_put_image(game, game->data.map.door_img, game->door.x, game->door.y);
}

void	ft_end_game(t_game *game)
{
	int	i;
	int	j;

	i = game->data.player.position.x;
	j = game->data.player.position.y;
	game->end_game = 1;
	ft_put_image(game, game->data.map.floor_img, i, j);
	mlx_destroy_image(game->mlx, game->data.map.door_img);
	game->data.map.door_img = ft_img_init(DOOR_C, game);
	ft_put_image(game, game->data.map.door_img, game->door.x, game->door.y);
	printf("\e[0;32mYou win!\e[0m\n");
}

void	ft_free_game(t_game *game)
{
	int	i;

	i = game->data.map.rows;
	while (i >= 0)
	{
		free(game->data.map.mtx[i]);
		i--;
	}
	free(game->data.map.mtx);
	free(game->data.map.str);
	close(game->data.map.fd);
}
