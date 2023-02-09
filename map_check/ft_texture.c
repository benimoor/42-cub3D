/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:04:49 by hvardany          #+#    #+#             */
/*   Updated: 2023/02/09 23:04:54 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_texture(t_cubd	*cubgame, char *str, char c)
{
	char	*tmp;

	if ((c == 'N' && cubgame->no) || (c == 'S' && cubgame->so)
		|| (c == 'W' && cubgame->we) || (c == 'E' && cubgame->ea))
		exit_game(cubgame, "Error! double value\n");
	tmp = ft_strtrim(str, "\n");
	if (c == 'N')
	{
		cubgame->no = ft_strtrim(tmp, " ");
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
	while (str && str[i] && ((str[i] >= '0'
				&& str[i] <= '9') || str[i] == ' '
			|| str[i] == '\t'))
	{
		i++;
	}
	if (k < 2 && str[i] && str[i] != ',')
		exit_game(cubgame, "ERROR: 1color\n");
	if (k == 2 && str[i] && (str[i] == ','
			|| (str[i] != 32 && str[i] != '\t' && str[i] != '\n')))
	{
		exit_game(cubgame, "ERROR: 2color\n");
	}
	return (i);
}

void	floor_or_ceiling(t_cubd	*cubgame, char *str, char c)
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

void	when_around_have_space(t_cubd *cubgame, char *str1,
	char *str2, char *str3)
{
	int	k;

	k = cubgame->zeros;
	if (!str2[k] || str2[k] == 32 || !str2[k - 1] || str2[k - 1] == 32
		|| !str2[k + 1] || str2[k + 1] == '\n'
		|| str2[k + 1] == 32 || !str1[k] || str1[k] == 32 || !str1[k - 1]
		|| str1[k - 1] == 32 || !str1[k + 1] || str1[k + 1] == '\n'
		|| str1[k + 1] == 32 || !str3[k] || str3[k] == 32 || !str3[k - 1]
		|| str3[k - 1] == 32 || !str3[k + 1] || str3[k + 1] == '\n'
		|| str3[k + 1] == 32)
		exit_game(cubgame, "ERROR: invalid map\n");
	check_around(cubgame, str1, str2, str3);
}

void	check_zero_around(t_cubd *cubgame, char	*str1, char *str2, char *str3)
{
	int	k;

	k = cubgame->zeros;
	cubgame->have_zerro = when_have_zerro(str2);
	when_around_have_space(cubgame, str1, str2, str3);
	if (str2[k] == '0' && str2[k + 1] == '1' && str2[k - 1] == '1'
		&& str3[k] == '0' && str1[k] == '0'
		&& (str1[k + 1] == '1' || str3[k +1] == '1'))
	str2[k] = 'D';
	else
		when_all_zerro(cubgame, str1, str2, str3);
}
