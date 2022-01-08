/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:36:34 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/08 17:35:11 by lamorim          ###   ########.fr       */
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
