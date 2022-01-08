/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:21:29 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/08 17:24:01 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_strmap_generator(t_data *data, char **line);

void	ft_read_map(t_data *data)
{
	char		*line;

	line = get_next_line(data->map.fd);
	if (!line)
	{
		printf(ERROR_3);
		exit (1);
	}
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
