/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:21:29 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/14 20:29:42 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_strmap_generator(t_game *game, char **line);
static void	ft_check_ns(t_game *game);
static void	ft_check_last_char(t_game *game);

void	ft_read_map(t_game *game)
{
	char		*line;

	line = get_next_line(game->data.map.fd);
	if (!line)
	{
		printf(ERROR_3, game->data.map.name);
		exit (1);
	}
	game->data.map.str = ft_strdup(line);
	ft_strmap_generator(game, &line);
	free(line);
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
	ft_check_last_char(game);
	ft_check_ns(game);
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

static void	ft_check_ns(t_game *game)
{
	int	i;
	int	len;
	int	flag;

	i = 0;
	flag = 0;
	len = ft_strlen(game->data.map.str) - 1;
	while (i < len)
	{
		if (game->data.map.str[i] == '\n' && game->data.map.str[i + 1] == '\n')
			flag++;
		i++;
	}
	if (flag)
	{
		free(game->data.map.str);
		printf(ERROR_8);
		exit (1);
	}
}

static void	ft_check_last_char(t_game *game)
{
	int		len;
	int		n;
	char	*str;

	n = 0;
	len = ft_strlen(game->data.map.str) - 1;
	if (game->data.map.str[len] == '\n')
	{
		while (game->data.map.str[len--] == '\n')
			n++;
	}
	len += 2;
	str = &game->data.map.str[len];
	ft_bzero(str, (size_t) n);
}
