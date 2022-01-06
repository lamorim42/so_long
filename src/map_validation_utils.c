/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:59:13 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/06 23:29:59 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_mtxmap_generator(t_data *data)
{
	data->map.mtx_map = ft_split(data->map.str_map, '\n');
}

int	ft_lines_cmp(t_data data)
{
	int	i;
	int	len_validation;

	i = 1;
	len_validation = ft_strlen(data.map.mtx_map[0]);
	while (data.map.mtx_map[i])
	{
		if (ft_strlen(data.map.mtx_map[i]) != len_validation)
		{
			printf(BHRED "\tError 04!" RESET " Invalid map composition.\n");
			return (1);
		}
		i++;
	}
	return (0);
}

//int	ft_map_validation(char *str_map)