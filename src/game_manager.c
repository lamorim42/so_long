/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 00:16:31 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/12 21:16:15 by lamorim          ###   ########.fr       */
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
	void	*temp;

	if (game->colletable == 0)
	{
		temp = game->data.map.door_img;
		game->data.map.door_img = ft_img_init(DOOR_O, game);
		ft_put_image(game, game->data.map.door_img, game->door.x, game->door.y);
		free(temp);
	}
}

void	ft_end_game(t_game *game)
{
	free(game->data.map.mtx);
	exit(1);
}
