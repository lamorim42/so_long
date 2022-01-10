/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:28:20 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/09 23:12:45 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_mtx(t_game *game);

void	ft_init_player(t_game *game, int j, int i)
{
	ft_put_image(game, game->data.player.img, j, i);
	game->data.player.position.x = j;
	game->data.player.position.y = i;
}

void	print_mtx(t_game *game)
{
	int	i;

	i = 0;
	while (i <= game->data.map.rows)
	{
		printf("%s\n", game->data.map.mtx[i]);
		i++;
	}
}
