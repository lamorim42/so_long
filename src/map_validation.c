/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:36:34 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/09 03:11:32 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_valid_nbr_arguments(int arg_c)
{
	if (arg_c != 2)
	{
		printf(ERROR_1);
		exit (1);
	}
}

int	ft_valid_map_extension(t_data *data)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_strrchr(data->map.name, '.');
	if (str)
	{
		len = ft_strlen(str);
		if (!ft_memcmp(str, ".ber", len))
			return (0);
	}
	printf(ERROR_2);
	exit(1);
	return (1);
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
			printf(ERROR_4);
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
		printf(ERROR_5);
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
			printf(ERROR_6);
			exit (1);
		}
	}
}
