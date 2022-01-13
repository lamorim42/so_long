/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 23:11:09 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/13 11:08:26 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_move_player(int key, t_game *game)
{
	int			*i;
	int			*j;

	i = &game->data.player.position.x;
	j = &game->data.player.position.y;
	if (key == W && game->data.map.mtx[*j - 1][*i] != '1')
		ft_move(game, ft_move_w, i, j);
	else if (key == S && game->data.map.mtx[*j + 1][*i] != '1')
		ft_move(game, ft_move_s, i, j);
	else if (key == A && game->data.map.mtx[*j][*i - 1] != '1')
		ft_move(game, ft_move_a, i, j);
	else if (key == D && game->data.map.mtx[*j][*i + 1] != '1')
		ft_move(game, ft_move_d, i, j);
	else if (key == ESC)
		ft_destroy_window(game);
	printf("%d\n", game->steps);
	return (0);
}

void	ft_move_w(t_game *game, int *i, int *j)
{
	if (game->data.map.mtx[*j - 1][*i] == 'C')
		game->colletable -= 1;
	if (game->data.map.mtx[*j - 1][*i] == 'E' \
	&& game->colletable == 0)
		ft_end_game(game);
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
		game->steps++;
	}
}

void	ft_move_s(t_game *game, int *i, int *j)
{
	if (game->data.map.mtx[*j + 1][*i] == 'C')
		game->colletable -= 1;
	if (game->data.map.mtx[*j + 1][*i] == 'E' \
	&& game->colletable == 0)
		ft_end_game(game);
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
		game->steps++;
	}
}

void	ft_move_a(t_game *game, int *i, int *j)
{
	if (game->data.map.mtx[*j][*i - 1] == 'C')
		game->colletable -= 1;
	if (game->data.map.mtx[*j][*i - 1] == 'E' \
	&& game->colletable == 0)
		ft_end_game(game);
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
		game->steps++;
	}
}

void	ft_move_d(t_game *game, int *i, int *j)
{
	if (game->data.map.mtx[*j][*i + 1] == 'C')
		game->colletable -= 1;
	if (game->data.map.mtx[*j][*i + 1] == 'E' \
	&& game->colletable == 0)
		ft_end_game(game);
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
		game->steps++;
	}
}
