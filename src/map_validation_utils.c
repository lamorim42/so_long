/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:59:13 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/08 01:28:45 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_mtxmap_generator(t_data *data)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	data->map.mtx_map = ft_split(data->map.str_map, '\n');
	while (data->map.str_map[i] != '\n')
		i++;
	data->map.colunms = i;
	i = 0;
	while (data->map.str_map[i])
	{
		if (data->map.str_map[i] == '\n')
			flag++;
		i++;
	}
	data->map.rows = flag;
}

void	ft_lines_cmp(t_data *data)
{
	int	i;
	int	len_validation;

	i = 1;
	len_validation = ft_strlen(data->map.mtx_map[0]);
	while (data->map.mtx_map[i])
	{
		if (ft_strlen(data->map.mtx_map[i]) != len_validation)
		{
			printf(BHRED "\tError 04!" RESET " Invalid map composition."\
			" Lines don't have same amount of chars.\n");
			exit (1);
		}
		i++;
	}
}

void	ft_check_map_itens(t_data *data)
{
	if (!ft_strrchr(data->map.str_map, 'C') \
	|| !ft_strrchr(data->map.str_map, 'E') \
	|| !ft_strrchr(data->map.str_map, 'P'))
	{
		printf(BHRED "\tError 05!" RESET " Invalid map composition."\
		" Missing mandatory item.\n");
		exit(1);
	}
}

void	ft_check_wrong_itens(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.str_map[i])
	{
		if (data->map.str_map[i] == '0' \
		|| data->map.str_map[i] == '1' \
		|| data->map.str_map[i] == 'P' \
		|| data->map.str_map[i] == 'C' \
		|| data->map.str_map[i] == 'E' \
		|| data->map.str_map[i] == '\n')
			i++;
		else
		{
			printf(BHRED "\tError 06!" RESET " Invalid map composition."\
			" Ivalid char on the map.\n");
			exit (1);
		}
	}
}

void	ft_check_border(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while ((data->map.mtx_map)[0][j])
	{
		if ((data->map.mtx_map[0][j]) != '1' \
		|| (data->map.mtx_map[data->map.rows][j]) != '1')
		{
			printf(ERROR_7);
			exit (1);
		}
		j++;
	}
	while (i < data->map.rows)
	{
		if ((data->map.mtx_map)[i][0] != '1' \
		|| (data->map.mtx_map)[i][j - 1] != '1')
		{
			printf(ERROR_7);
			exit (1);
		}
		i++;
	}
}
//int	ft_map_validation(char *str_map)