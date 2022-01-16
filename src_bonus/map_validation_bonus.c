/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:36:34 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/14 22:51:52 by lamorim          ###   ########.fr       */
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

int	ft_valid_map_extension(t_game *game)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_strrchr(game->data.map.name, '.');
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

void	ft_lines_cmp(t_game *game)
{
	int		i;
	size_t	len_validation;

	i = 1;
	len_validation = ft_strlen(game->data.map.mtx[0]);
	while (game->data.map.mtx[i])
	{
		if (ft_strlen(game->data.map.mtx[i]) != len_validation)
		{
			ft_free_game(game);
			printf(ERROR_4);
			exit(1);
		}
		i++;
	}
}

void	ft_check_map_items(t_game *game)
{
	if (!ft_strrchr(game->data.map.str, 'C') \
	|| !ft_strrchr(game->data.map.str, 'E') \
	|| !ft_strrchr(game->data.map.str, 'P'))
	{
		ft_free_game(game);
		printf(ERROR_5);
		exit(1);
	}
}

void	ft_check_wrong_items(t_game *game)
{
	int	i;

	i = 0;
	while (game->data.map.str[i])
	{
		if (game->data.map.str[i] == '0' \
		|| game->data.map.str[i] == '1' \
		|| game->data.map.str[i] == 'P' \
		|| game->data.map.str[i] == 'C' \
		|| game->data.map.str[i] == 'E' \
		|| game->data.map.str[i] == 'V' \
		|| game->data.map.str[i] == '\n')
			i++;
		else
		{
			ft_free_game(game);
			printf(ERROR_6);
			exit (1);
		}
	}
}
