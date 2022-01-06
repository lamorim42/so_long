/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:36:34 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/06 23:49:26 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_strmap_generator(t_data *data, char **line);

int	ft_valid_nbr_arguments(int arg_c)
{
	if (arg_c != 2)
	{
		printf(BHRED "\tError 01!" RESET " Invalid number of argumeets.\n");
		return (1);
	}
	return (0);
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
	printf(BHRED "\tError 02!" RESET " Invalid map format.\n");
	return (1);
}

void	ft_read_map(t_data *data)
{
	char		*line;

	line = get_next_line(data->map.fd);
	if (!line)
		printf(BHRED "\tError 03!" RESET " Null read, nonexistent map.\n");
	data->map.str_map = ft_strdup(line);
	ft_strmap_generator(data, &line);
}

static void	ft_strmap_generator(t_data *data, char **line)
{
	char	*temp;

	while (*line)
	{
		temp = *line;
		*line = get_next_line(data->map.fd);
		if (!*line)
		{
			free(temp);
			break ;
		}
		free(temp);
		temp = data->map.str_map;
		data->map.str_map = ft_strjoin(data->map.str_map, *line);
		free(temp);
	}
}
