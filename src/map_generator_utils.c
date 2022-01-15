/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:36:53 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/14 17:40:28 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_plr_or_flr(t_game *game, int i, int j);

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
		ft_put_image(game, game->data.player.img, j, i);
		game->data.player.position.x = j;
		game->data.player.position.y = i;
		(*flag)++;
	}
	else
	{
		game->data.map.mtx[i][j] = '0';
		ft_put_image(game, game->data.map.floor_img, j, i);
	}
}

int	ft_map_redraw(t_game *game)
{
	int			i;
	int			j;

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
				ft_put_image(game, game->data.map.door_img, j, i);
			else if (game->data.map.mtx[i][j] == 'P')
				ft_plr_or_flr(game, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

static void	ft_plr_or_flr(t_game *game, int i, int j)
{
	if (game->end_game)
		ft_put_image(game, game->data.map.floor_img, j, i);
	else
		ft_put_image(game, game->data.player.img, j, i);
}
