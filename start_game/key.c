/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:09:53 by hvardany          #+#    #+#             */
/*   Updated: 2023/02/09 23:09:55 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	func_closs_dor(t_cubd	*cubgame, int i, int j, char s)
{
	int		a;
	int		b;
	t_list	*g;
	char	*str;

	a = (int) cubgame->px;
	b = (int) cubgame->py;
	g = cubgame->grafic;
	if (cubgame->dor_i == i && cubgame->dor_j == j && cubgame->is_key == '1')
	{
		if ((cubgame->dor_i != a || cubgame->dor_j != b)
			&& cubgame->flag_dor_open == '1')
		{
			cubgame->flag_dor_open = '0';
			if (i < 0 || j < 0)
				return ;
			while (j-- > 0)
				g = g->next;
			str = g->content;
			str[j] = s;
		}
	}
}

void	func_e(t_cubd	*cubgame)
{
	int		j;
	int		i;
	char	s;

	i = cubgame->px + (cubgame->dx * 0.5);
	j = cubgame->py + (cubgame->dy * 0.5);
	s = s_read(i, j, cubgame);
	if (s == 'D' && cubgame->is_key == '1')
		func_open_dor(cubgame, i, j, '0');
	else
		func_closs_dor(cubgame, i, j, s);
}

void	func_l(t_cubd	*cubgame)
{
	cubgame->pozition = cubgame->pozition + 5;
	if (cubgame->pozition >= 360)
		cubgame->pozition = cubgame->pozition - 360;
	cubgame->dx = cos(cubgame->pozition * 3.1415 / 180);
	cubgame->dy = sin(cubgame->pozition * 3.1415 / 180);
}

void	key_l_r(t_cubd	*cubgame, int keyx)
{
	if (keyx == 123)
	{
		cubgame->pozition = cubgame->pozition + 5;
		if (cubgame->pozition >= 360)
			cubgame->pozition = cubgame->pozition - 360;
		else if (cubgame->pozition <= -1)
		cubgame->pozition = cubgame->pozition + 360;
		cubgame->dx = cos(cubgame->pozition * 3.1415 / 180);
		cubgame->dy = -1 * sin(cubgame->pozition * 3.1415 / 180);
	}
	else if (keyx == 124)
	{
		cubgame->pozition = cubgame->pozition - 5;
		if (cubgame->pozition >= 360)
			cubgame->pozition = cubgame->pozition - 360;
		else if (cubgame->pozition <= -1)
			cubgame->pozition = cubgame->pozition + 360;
		cubgame->dx = cos(cubgame->pozition * 3.1415 / 180);
		cubgame->dy = -1 * sin(cubgame->pozition * 3.1415 / 180);
	}
}

int	key(int keyx, t_cubd *cubgame)
{
	if (keyx == 13)
		func_w(cubgame);
	else if (keyx == 1)
		func_s(cubgame);
	else if (keyx == 0)
		func_a(cubgame);
	else if (keyx == 2)
		func_d(cubgame);
	else if (keyx == 53)
		exit_and_distroy(cubgame);
	else if (keyx == 14)
		func_e(cubgame);
	else
		key_l_r(cubgame, keyx);
	return (0);
}
