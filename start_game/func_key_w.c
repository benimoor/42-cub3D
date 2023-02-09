/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_key_w.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:09:45 by hvardany          #+#    #+#             */
/*   Updated: 2023/02/09 23:09:47 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_nol(int i, int j, t_cubd *cubgame, char c)
{
	char	*s;
	t_list	*g;

	g = cubgame->grafic;
	if (i < 0 || j < 0)
		return ;
	while (j-- > 0)
		g = g->next;
	s = g->content;
	printf("%s\n", s);
	s[i] = c;
}

char	s_read(int i, int j, t_cubd *cubgame)
{
	t_list	*map;
	char	*s;

	if (i < 0 || j < 0 || i >= cubgame->width || j >= cubgame->height)
		return (' ');
	map = cubgame->grafic;
	while (j > 0)
	{
		j--;
		map = map->next;
	}
	s = map->content;
	return (s[i]);
}

void	func_s_read_2(int i, int j, t_cubd *cubgame, char *s)
{
	t_list	*g;
	char	*s1;

	if (i >= 0 && j >= 0 && i < cubgame->width && j < cubgame->height)
	{
		g = cubgame->grafic;
		while (j-- > 0)
			g = g->next;
		s1 = (char *)g->content;
		*s = s1[i];
	}
	else
		*s = ' ';
}

void	func_w(t_cubd	*cubgame)
{
	int		j;
	int		i;
	char	s;

	i = cubgame->px + (cubgame->dx * 0.2);
	j = cubgame->py + (cubgame->dy * 0.2);
	s = s_read(i, j, cubgame);
	if (s != '0' && s != 'K')
		return ;
	if (s == 'K')
	{
		cubgame->is_key = '1';
		cubgame->sprite = '0';
		set_nol(i, j, cubgame, '0');
	}
	cubgame->px += (cubgame->dx * 0.1);
	cubgame->py += (cubgame->dy * 0.1);
	if (cubgame->steps)
		cubgame->steps += 1;
}
