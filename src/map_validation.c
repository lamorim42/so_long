/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamorim <lamorim@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:36:34 by lamorim           #+#    #+#             */
/*   Updated: 2022/01/05 21:45:46 by lamorim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_count(char **line);

int	ft_valid_nbr_arguments(int arg_c)
{
	if (arg_c != 2)
	{
		printf(BHRED "\tError 01!" RESET " Invalid number of argumeets.\n");
		return (1);
	}
	return (0);
}

int	ft_valid_map_extension(char *map_name)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_strrchr(map_name, '.');
	if (str)
	{
		len = ft_strlen(str);
		if (!ft_memcmp(str, ".ber", len))
			return (0);
	}
	printf(BHRED "\tError 02!" RESET " Invalid map format.\n");
	return (1);
}

int	ft_map_read(int fd)
{
	// usar join pra concatenar todas as strings e a split pra gerar matriz do mapa
	t_map		map;
	char		*line;
	int			nbr_chr;
	static int	*validation_line = NULL;

	line = get_next_line(fd);
	if (!validation_line)
	{
		validation_line = malloc(sizeof(int));
		*validation_line = ft_count(&line);
	}
	while (line)
	{
		line = get_next_line(fd);
		nbr_chr = ft_count(&line);
		if (*validation_line != (nbr_chr - 1) && line)
		{
			printf(BHRED "\tError 03!" RESET " Invalid map, The rows don't"\
			" have the same amount of chars.\n");
			return (1);
		}
	}
	return (0);
}

static int	ft_count(char **line)
{
	int	i;

	while ((*line)[i])
		i++;
	return (i - 1);
}
