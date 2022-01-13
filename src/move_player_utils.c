/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:04:04 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/13 17:18:24 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_init_player(t_game *game, int j, int i)
{
	ft_put_image(game, game->data.player.img, j, i);
	game->data.player.position.x = j;
	game->data.player.position.y = i;
}

void	ft_move(t_game *game, void (*f)(t_game *game, int *i, int *j), \
int *i, int *j)
{
	(*f)(game, i, j);
	ft_open_door(game);
}
