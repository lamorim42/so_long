/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:59:13 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/09 09:37:03 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
		{
			printf(ERROR_7);
			exit (1);
		}
		j++;
	}
	while (i < game->data.map.rows)
	{
		if ((game->data.map.mtx)[i][0] != '1' \
		|| (game->data.map.mtx)[i][j - 1] != '1')
		{
			printf(ERROR_7);
			exit (1);
		}
		i++;
	}
}
