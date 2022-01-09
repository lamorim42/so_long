/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:59:13 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/09 03:33:54 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
