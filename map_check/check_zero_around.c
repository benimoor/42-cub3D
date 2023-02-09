/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zero_around.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:04:36 by hvardany          #+#    #+#             */
/*   Updated: 2023/02/09 23:04:41 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	when_have_zerro(char	*str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] == '0')
			return (0);
		i++;
	}
	return (0);
}

void	when_all_zerro(t_cubd *cubgame, char	*str1, char *str2, char *str3)
{
	int	k;

	k = cubgame->i;
	if (str2[k] == '0')
	{
		if (cubgame->is_key == '0' && str1[k] == '0' && str1[k + 1] == '0'
			&& str1[k - 1] == '0' && str2[k] == '0' && str2[k + 1] == '0'
			&& str2[k - 1] == '0' && str3[k] == '0' && str3[k + 1] == '0'
			&& str3[k - 1] == '0')
		{
			cubgame->is_key = '1';
			str2[k] = 'K';
			cubgame->keypx = k;
		}
	}
}

int	char_walid(char str)
{
	if (!str || str == '\n')
		return (1);
	if (str == '1' || str == '0' || str == 'W' || str == 'N'
		|| str == 'S' || str == 'E' || str == 'K' || str == 'D')
		return (1);
	return (0);
}

int	char_walid1(char str)
{
	if (str == '0' || str == 'W' || str == 'N'
		|| str == 'S' || str == 'E' || str == 'K' || str == 'D')
		return (1);
	return (0);
}

void	check_around(t_cubd *cubgame, char	*str1, char *str2, char *str3)
{
	int	k;

	k = cubgame->i;
	if (str2[k] && char_walid1(str2[k]) && !char_walid(str2[k + 1]))
		exit_game(cubgame, "ERROR: 1invalid map\n");
	if (str2[k] && char_walid1(str2[k]) && !char_walid(str2[k - 1]))
	{
		exit_game(cubgame, "ERROR: 2invalid map\n");
	}
	if (str2[k] && char_walid1(str2[k]) && !char_walid(str1[k + 1]))
		exit_game(cubgame, "ERROR: 3invalid map\n");
	if (str2[k] && char_walid1(str2[k]) && !char_walid(str1[k - 1]))
		exit_game(cubgame, "ERROR: 4invalid map\n");
	if (str2[k] && char_walid1(str2[k]) && !char_walid(str3[k - 1]))
		exit_game(cubgame, "ERROR: 5invalid map\n");
	if (str2[k] && char_walid1(str2[k]) && !char_walid(str3[k + 1]))
		exit_game(cubgame, "ERROR: 6invalid map\n");
	if (char_walid1(str2[k]) && (ft_strlen(str1) < (size_t)(k + 1)
		|| ft_strlen(str3) < (size_t)(k + 1)))
		exit_game(cubgame, "ERROR: 7invalid map\n");
}
