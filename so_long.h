/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:30:37 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/09 03:09:08 by lamorim          ###   ########.fr       */
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

# define ERROR_1 "\e[1;91m \tError 01! \e[0m Invalid number of argumeets.\n"
# define ERROR_2 "\e[1;91m \tError 02! \e[0m Invalid map extension.\n"
# define ERROR_3 "\e[1;91m \tError 03! \e[0m Null read, nonexistent map.\n"
# define ERROR_4 "\e[1;91m \tError 04! \e[0m Invalid map composition.\
 Map is not a rectangle.\n"
# define ERROR_5 "\e[1;91m \tError 04! \e[0m Invalid map composition.\
 Missing mandatory item.\n"
# define ERROR_6 "\e[1;91m \tError 04! \e[0m Invalid map composition.\
 Ivalid char on the map.\n"
# define ERROR_7 "\e[1;91m \tError 07! \e[0m Invalid map composition.\
 Ivalid char on the map border.\n"

typedef struct s_position {
	int	x;
	int	y;
}				t_position;

typedef struct s_vars {
	void		*mlx;
	void		*win;
}				t_vars;

typedef struct s_map {
	int		fd;
	int		arg_c;
	char	*name;
	char	*str_map;
	char	**mtx_map;
	int		rows;
	int		colunms;
}				t_map;

typedef struct s_data {
	t_map	map;
}				t_data;

void	ft_valid_nbr_arguments(int arg_c);
int		ft_valid_map_extension(t_data *data);
void	ft_read_map(t_data *data);
void	ft_mtxmap_generator(t_data *data);
void	ft_lines_cmp(t_data *data);
void	ft_check_map_itens(t_data *data);
void	ft_check_wrong_itens(t_data *data);
void	ft_check_border(t_data *data);

#endif
