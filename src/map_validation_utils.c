/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:59:13 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/13 15:46:51 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_free_print(t_game *game);

void	ft_map_validation(t_game *game)
{
	ft_valid_map_extension(game);
	ft_read_map(game);
	ft_mtxmap_generator(game);
	if (!game->data.map.str)
		exit(1);
	ft_lines_cmp(game);
	ft_check_map_itens(game);
	ft_check_wrong_itens(game);
	ft_check_border(game);
}

void	ft_check_border(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while ((game->data.map.mtx)[0][j])
	{
		if ((game->data.map.mtx[0][j]) != '1' \
		|| (game->data.map.mtx[game->data.map.rows][j]) != '1')
			ft_free_print(game);
		j++;
	}
	while (i < game->data.map.rows)
	{
		if ((game->data.map.mtx)[i][0] != '1' \
		|| (game->data.map.mtx)[i][j - 1] != '1')
			ft_free_print(game);
		i++;
	}
}

static void	ft_free_print(t_game *game)
{
	ft_free_game(game);
	printf(ERROR_7);
	exit (1);
}
