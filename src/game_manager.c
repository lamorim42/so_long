/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 00:16:31 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/10 00:35:34by lamorim          ###   ########.fr       */
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

void	ft_find_door(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->data.map.rows)
	{
		j = 0;
		while (j < game->data.map.colunms)
		{
			if (game->data.map.mtx[i][j] == 'E')
			{
				game->door.x = j;
				game->door.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_open_door(t_game *game)
{
	if (game->colletable == 0)
	{
		game->data.map.door_img = ft_img_init(DOOR_O, game);
		ft_put_image(game, game->data.map.door_img, game->door.x, game->door.y);
	}
}

//void	ft_end_game(t_game *game)
//{
//	if (game->colletable == 0)
//}
