/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_closs_dor1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:07:50 by hvardany          #+#    #+#             */
/*   Updated: 2023/02/09 23:07:54 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	func_a(t_cubd	*cubgame)
{
	int		j;
	int		i;
	char	s;

	i = cubgame->px + (cubgame->dy * 0.2);
	j = cubgame->py - (cubgame->dx * 0.2);
	s = s_read(i, j, cubgame);
	if (s != '0' && s != 'K')
		return ;
	if (s == 'K')
	{
		cubgame->is_key = '1';
		cubgame->sprite = '0';
		set_nol(i, j, cubgame, '0');
	}
	cubgame->px = cubgame->px + (cubgame->dy * 0.1);
	cubgame->py = cubgame->py - (cubgame->dx * 0.1);
	if (cubgame->steps)
		cubgame->steps++;
}

void	func_s(t_cubd	*cubgame)
{
	int		j;
	int		i;
	char	s;

	i = cubgame->px - (cubgame->dx * 0.2);
	j = cubgame->py - (cubgame->dy * 0.2);
	s = s_read(i, j, cubgame);
	if (s != '0' && s != 'K')
		return ;
	if (s == 'K')
	{
		cubgame->is_key = '1';
		cubgame->sprite = '0';
		set_nol(i, j, cubgame, '0');
	}
	cubgame->px = cubgame->px - (cubgame->dx * 0.1);
	cubgame->py = cubgame->py - (cubgame->dy * 0.1);
	if (cubgame->steps)
	cubgame->steps++;
}

void	func_d(t_cubd	*cubgame)
{
	int		j;
	int		i;
	char	s;

	i = cubgame->px - (cubgame->dy * 0.2);
	j = cubgame->py + (cubgame->dx * 0.2);
	s = s_read(i, j, cubgame);
	if (s != '0' && s != 'K')
		return ;
	if (s == 'K')
	{
		cubgame->is_key = '1';
		cubgame->sprite = '0';
		set_nol(i, j, cubgame, '0');
	}
	cubgame->px = cubgame->px - (cubgame->dy * 0.1);
	cubgame->py = cubgame->py + (cubgame->dx * 0.1);
	if (cubgame->steps)
	cubgame->steps++;
}

void	func_open_dor(t_cubd	*cubgame, int i, int j, char s)
{
	char	*str;
	t_list	*g;

	g = cubgame->grafic;
	cubgame->dor_i = i;
	cubgame->dor_j = j;
	if (i < 0 || j < 0)
		return ;
	while (j-- > 0)
		g = g->next;
	str = g->content;
	str[j] = s;
	cubgame->flag_dor_open = '1';
	cubgame->steps = 1;
}

void	func_closs_dor1(t_cubd	*cubgame, int i, int j, char s)
{
	int		a;
	int		b;
	t_list	*g;
	char	*str;

	a = (int) cubgame->px;
	b = (int) cubgame->py;
	if (cubgame->dor_j != j && cubgame->flag_dor_open == '1')
	{
		cubgame->flag_dor_open = '0';
		while (i-- > 0)
			g = g->next;
		str = g->content;
		str[j] = s;
	}
}
