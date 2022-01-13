/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:04:04 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/12 19:11:52 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move(t_game *game, void (*f)(t_game *game, int *i, int *j), \
int *i, int *j)
{
	(*f)(game, i, j);
	ft_open_door(game);
}
