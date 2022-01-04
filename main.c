#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

# define W 0x77
# define S 0x73
# define A 0x61
# define D 0x64
# define ESC 0xff1b

typedef struct	s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct	s_vars
{
	void		*mlx;
	void		*win;
	t_position	position;
}	t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	return(0);
}

int	destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

int	close_esc(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		destroy(vars);
	return (0);
}

int	main(void)
{
	t_vars		vars;
	t_position	position;
	void		*ptr;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	printf("Test!\n");
	ptr = mlx_xpm_file_to_image(vars.mlx, "./src/images/test.xpm", &position.x, &position.y);
	position.x = 300;
	position.y = 300;
	printf("%p\n", ptr);
	mlx_put_image_to_window(vars.mlx, vars.win, ptr, position.x, position.y);
	mlx_hook(vars.win, 2, 1L<<0, close_esc, &vars);
	mlx_hook(vars.win, 17, 0L, destroy, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
