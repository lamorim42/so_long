/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:18:17 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/16 17:55:30 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_help_draw(t_game *game, int i, int j)
{
	static int	p_flag = 0;
	static int	d_flag = 0;

	if (game->data.map.mtx[i][j] == '1')
		ft_put_image(game, game->data.map.wall_img, j, i);
	else if (game->data.map.mtx[i][j] == '0')
		ft_put_image(game, game->data.map.floor_img, j, i);
	else if (game->data.map.mtx[i][j] == 'C')
		ft_put_image(game, game->data.map.collet_img, j, i);
	else if (game->data.map.mtx[i][j] == 'V')
		ft_put_image(game, game->data.map.enemy_img, j, i);
	else if (game->data.map.mtx[i][j] == 'E')
		ft_put_door(game, i, j, &d_flag);
	else if (game->data.map.mtx[i][j] == 'P')
		ft_put_player(game, i, j, &p_flag);
}

void	ft_print_steps(t_game *game)
{
	char	*steps;

	steps = ft_itoa(game->steps);
	mlx_string_put(game->mlx, game->win, 8, 15, 0xFFFF00, "Moves:");
	mlx_string_put(game->mlx, game->win, 49, 15, 0xFFFF00, steps);
	free(steps);
}
