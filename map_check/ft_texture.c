#include "../cub3d.h"

void	ft_texture(t_cubd	*cubgame, char  *str, char c)
{
	char	*tmp;

// printf("----------%c--[%s]\n", c, str);
	if ((c == 'N' && cubgame->no) || (c == 'S' && cubgame->so)
		|| (c == 'W' && cubgame->we) || (c == 'E' && cubgame->ea))
		exit_game(cubgame, "Error! double value\n");
	tmp = ft_strtrim(str, "\n");
	if (c == 'N')
	{
		cubgame->no = ft_strtrim(tmp, " ");
// printf("\nNNNNNNNNNNNNN   [%s]\n",cubgame->no);
	}
	else if (c == 'S')
		cubgame->so = ft_strtrim(tmp, " ");
	else if (c == 'W')
		cubgame->we = ft_strtrim(tmp, " ");
	else if (c == 'E')
		cubgame->ea = ft_strtrim(tmp, " ");
	free(tmp);
}

int	count_number(t_cubd	*cubgame, char *str, int k)
{
	int	i;

	i = 0;
	while (str && str[i]
		&& ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ' || str[i] == '\t'))
		{
			i++;
		}
	if (k < 2 && str[i] && str[i] != ',')
		exit_game(cubgame, "ERROR: 1color\n");
	if (k == 2 && str[i] && (str[i] == ',' || (str[i] != 32 && str[i] != '\t' && str[i] != '\n')))
	{
		exit_game(cubgame, "ERROR: 2color\n");
	}
	return (i);
}

void	floor_or_ceiling(t_cubd	*cubgame, char  *str, char c)
{
	int		k;
	int		count;
	char	*s;

	k = 0;
	while (str && *str && (*str == 32 || *str == '\t'))
		str++;
	while (k < 3)
	{
		count = count_number(cubgame, str, k);
		s = ft_substr(str, 0, count);
		if (str[count] == ',')
			count++;
		str += count;
		count = ft_atoi(s);
		free(s);
		if (count > 255 || count < 0)
			exit_game(cubgame, "Error: color it is not in the range 0, 255\n");
		if (c == 'C')
			cubgame->c[k] = count;
		else if (c == 'F')
			cubgame->f[k] = count;
		k++;
	}
	
}