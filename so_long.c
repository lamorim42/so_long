/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:36:17 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/13 17:17:11 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game		game;

	ft_valid_nbr_arguments(argc);
	game.data.map.name = argv[1];
	game.data.map.fd = open(game.data.map.name, O_RDONLY);
	ft_map_validation(&game);
	ft_window_size(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, \
	(game.win_width), (game.win_height), "so_long");
	ft_all_img_init(&game);
	ft_map_drow(&game);
	ft_game_init(&game);
	mlx_hook(game.win, 2, 1L << 0, ft_move_player, &game);
	mlx_hook(game.win, 17, 0L, ft_destroy_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
