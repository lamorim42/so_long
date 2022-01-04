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
	void		*ptr;

	if (ft_valid_nbr_arguments(argc))
		exit(1);
	if (ft_valid_map_extension(argv[1]))
		exit(1);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	//printf("Test!\n");
	ptr = mlx_xpm_file_to_image(vars.mlx, "./src/images/test.xpm", &position.x, &position.y);
	position.x = 300;
	position.y = 300;
	//printf("%p\n", ptr);
	mlx_put_image_to_window(vars.mlx, vars.win, ptr, position.x, position.y);
	mlx_hook(vars.win, 2, 1L<<0, ft_close_esc, &vars);
	mlx_hook(vars.win, 17, 0L, ft_destroy_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
