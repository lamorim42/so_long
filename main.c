/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:36:17 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/07 00:21:16 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_destroy_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	ft_close_esc(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		ft_destroy_window(vars);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars		vars;
	t_position	position;
	t_data		data;
	void		*ptr;

	data.map.name = argv[1];
	if (ft_valid_nbr_arguments(argc) || ft_valid_map_extension(&data))
		exit(1);
	data.map.fd = open(data.map.name, O_RDONLY);
	ft_read_map(&data);
	ft_mtxmap_generator(&data);
	if (!data.map.str_map)
		exit(1);
	if (ft_lines_cmp(data))
		exit(1);
	/*
	printf("%s\n", data.map.mtx_map[0]);
	printf("%s\n", data.map.mtx_map[1]);
	printf("%s\n", data.map.mtx_map[2]);
	printf("%s\n", data.map.mtx_map[3]);
	printf("%s\n", data.map.mtx_map[4]);
	*/
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	ptr = mlx_xpm_file_to_image(vars.mlx, "./src/images/test.xpm", \
	&position.x, &position.y);
	position.x = 300;
	position.y = 300;
	mlx_put_image_to_window(vars.mlx, vars.win, ptr, position.x, position.y);
	mlx_hook(vars.win, 2, 1L << 0, ft_close_esc, &vars);
	mlx_hook(vars.win, 17, 0L, ft_destroy_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
