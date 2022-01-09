/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:21:29 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/09 09:36:37 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_strmap_generator(t_game *game, char **line);

void	ft_read_map(t_game *game)
{
	char		*line;

	line = get_next_line(game->data.map.fd);
	if (!line)
	{
		printf(ERROR_3);
		exit (1);
	}
	game->data.map.str = ft_strdup(line);
	ft_strmap_generator(game, &line);
}

static void	ft_strmap_generator(t_game *game, char **line)
{
	char	*temp;

	while (*line)
	{
		temp = *line;
		*line = get_next_line(game->data.map.fd);
		if (!*line)
		{
			free(temp);
			break ;
		}
		free(temp);
		temp = game->data.map.str;
		game->data.map.str = ft_strjoin(game->data.map.str, *line);
		free(temp);
	}
}

void	ft_mtxmap_generator(t_game *game)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	game->data.map.mtx = ft_split(game->data.map.str, '\n');
	while (game->data.map.str[i] != '\n')
		i++;
	game->data.map.colunms = i;
	i = 0;
	while (game->data.map.str[i])
	{
		if (game->data.map.str[i] == '\n')
			flag++;
		i++;
	}
	game->data.map.rows = flag;
}
