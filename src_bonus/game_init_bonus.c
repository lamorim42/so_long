/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 23:21:28 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/15 14:12:05 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_game_init(t_game *game)
{
	ft_collet_count(game);
	game->steps = 0;
	game->end_game = 0;
	game->lose = 0;
	game->data.player.sprite = 'F';
}
