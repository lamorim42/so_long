/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:36:17 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/09 10:57:10 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_destroy_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

int	ft_close_esc(int keycode, t_game *game)
{
	if (keycode == ESC)
		ft_destroy_window(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game		game;
	t_position	position;
	void		*ptr;

	// map validation
	game.data.map.name = argv[1];
	game.data.map.fd = open(game.data.map.name, O_RDONLY);
	ft_valid_nbr_arguments(argc);
	ft_read_map(&game);
	ft_valid_map_extension(&game);
	ft_mtxmap_generator(&game);
	if (!game.data.map.str)
		exit(1);
	ft_lines_cmp(&game);
	ft_check_map_itens(&game);
	ft_check_wrong_itens(&game);
	ft_check_border(&game);
	// map generator
	ft_window_size(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, \
	(game.win_width), (game.win_height), "Hello world!");
	printf("(%d, %d)\n", (game.data.map.colunms * SPRITE_SIZE), ((game.data.map.rows + 1) * SPRITE_SIZE));
	ft_all_img_init(&game);
	ft_map_drow(&game);
	mlx_hook(game.win, 2, 1L << 0, ft_close_esc, &game);
	mlx_hook(game.win, 17, 0L, ft_destroy_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
