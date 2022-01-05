/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:30:37 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/05 21:26:07 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

//High intensty background
# define BLKHB "\e[0;100m"
# define REDHB "\e[0;101m"
# define GRNHB "\e[0;102m"
# define YELHB "\e[0;103m"
# define BLUHB "\e[0;104m"
# define MAGHB "\e[0;105m"
# define CYNHB "\e[0;106m"
# define WHTHB "\e[0;107m"

//Bold high intensity text
# define BHBLK "\e[1;90m"
# define BHRED "\e[1;91m"
# define BHGRN "\e[1;92m"
# define BHYEL "\e[1;93m"
# define BHBLU "\e[1;94m"
# define BHMAG "\e[1;95m"
# define BHCYN "\e[1;96m"
# define BHWHT "\e[1;97m"

//Reset
# define RESET "\e[0m"

# define W 0x77
# define S 0x73
# define A 0x61
# define D 0x64
# define ESC 0xff1b

typedef struct s_position {
	int	x;
	int	y;
}				t_position;

typedef struct s_vars {
	void		*mlx;
	void		*win;
}				t_vars;

typedef struct s_map {
	char	*name;
	int		rows;
	int		columns;
}				t_map;

typedef struct s_data {
	t_map	map;
}				t_data;

int	ft_valid_nbr_arguments(int arg_c);
int	ft_valid_map_extension(char *arg_v);
int	ft_map_read(int fd);

#endif
