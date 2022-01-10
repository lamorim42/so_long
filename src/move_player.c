/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 23:11:09 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/10 03:43:23 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_move_player(int key, t_game *game)
{
	int	*i;
	int	*j;

	i = &game->data.player.position.x;
	j = &game->data.player.position.y;
	printf("%d <---\n", game->colletable);
	if (key == W && game->data.map.mtx[*j - 1][*i] != '1')
	{
		if (game->data.map.mtx[*j - 1][*i] == 'C')
			game->colletable -= 1;
		ft_move_w(game);
		ft_open_door(game);
	}
	else if (key == S && game->data.map.mtx[*j + 1][*i] != '1')
	{
		if (game->data.map.mtx[*j + 1][*i] == 'C')
			game->colletable -= 1;
		ft_move_s(game);
		ft_open_door(game);
	}
	else if (key == A && game->data.map.mtx[*j][*i - 1] != '1')
	{
		if (game->data.map.mtx[*j][*i - 1] == 'C')
			game->colletable -= 1;
		ft_move_a(game);
		ft_open_door(game);
	}
	else if (key == D && game->data.map.mtx[*j][*i + 1] != '1')
	{
		if (game->data.map.mtx[*j][*i + 1] == 'C')
			game->colletable -= 1;
		ft_move_d(game);
		ft_open_door(game);
	}
	else if (key == ESC)
		ft_destroy_window(game);
	return (0);
}

void	ft_move_w(t_game *game)
{
	int	*i;
	int	*j;

	i = &game->data.player.position.x;
	j = &game->data.player.position.y;
	if (game->data.map.mtx[*j - 1][*i] == 'E' \
	&& game->colletable == 0)
		exit(1);
	else if (game->data.map.mtx[*j - 1][*i] == 'E' \
	&& game->colletable != 0)
		return ;
	else
	{
		game->data.map.mtx[*j][*i] = '0';
		game->data.map.mtx[*j - 1][*i] = 'P';
		ft_put_image(game, game->data.map.floor_img, *i, *j);
		ft_put_image(game, game->data.player.img, *i, *j - 1);
		*j -= 1;
	}
}

void	ft_move_s(t_game *game)
{
	int	*i;
	int	*j;

	i = &game->data.player.position.x;
	j = &game->data.player.position.y;
	if (game->data.map.mtx[*j + 1][*i] == 'E' \
	&& game->colletable == 0)
		exit(1);
	else if (game->data.map.mtx[*j + 1][*i] == 'E' \
	&& game->colletable != 0)
		return ;
	else
	{
		game->data.map.mtx[*j][*i] = '0';
		game->data.map.mtx[*j + 1][*i] = 'P';
		ft_put_image(game, game->data.map.floor_img, *i, *j);
		ft_put_image(game, game->data.player.img, *i, *j + 1);
		*j += 1;
	}
}

void	ft_move_a(t_game *game)
{
	int	*i;
	int	*j;

	i = &game->data.player.position.x;
	j = &game->data.player.position.y;
	if (game->data.map.mtx[*j][*i - 1] == 'E' \
	&& game->colletable == 0)
		exit(1);
	else if (game->data.map.mtx[*j][*i - 1] == 'E' \
	&& game->colletable != 0)
		return ;
	else
	{
		game->data.map.mtx[*j][*i] = '0';
		game->data.map.mtx[*j][*i - 1] = 'P';
		ft_put_image(game, game->data.map.floor_img, *i, *j);
		ft_put_image(game, game->data.player.img, *i - 1, *j);
		*i -= 1;
	}
}

void	ft_move_d(t_game *game)
{
	int	*i;
	int	*j;

	i = &game->data.player.position.x;
	j = &game->data.player.position.y;
	if (game->data.map.mtx[*j][*i + 1] == 'E' \
	&& game->colletable == 0)
		exit(1);
	else if (game->data.map.mtx[*j][*i + 1] == 'E' \
	&& game->colletable != 0)
		return ;
	else
	{
		game->data.map.mtx[*j][*i] = '0';
		game->data.map.mtx[*j][*i + 1] = 'P';
		ft_put_image(game, game->data.map.floor_img, *i, *j);
		ft_put_image(game, game->data.player.img, *i + 1, *j);
		*i += 1;
	}
}
