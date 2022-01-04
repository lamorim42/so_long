#include "../so_long.h"

int	ft_valid_nbr_arguments(int arg_c)
{
	if (arg_c != 2)
	{
		printf(BHRED "\tError 1!" reset " Invalid number of argumeets.\n");
		return (1);
	}
	return (0);
}

int	ft_valid_map_extension(char *arg_v)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_strrchr(arg_v, '.');
	if (str)
	{
		len = ft_strlen(str);
		if (!ft_memcmp(str, ".ber", len))
			return (0);
	}
	printf(BHRED "\tError 2!" reset " Invalid map format.\n");
	return (1);
}
