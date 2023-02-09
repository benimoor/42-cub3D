/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_player_start_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:15:19 by ergrigor          #+#    #+#             */
/*   Updated: 2023/02/09 23:15:20 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	pixel_set_unset_s_h1(t_cubd *cubgame, int i, int j, int c)
{
	char	*dst;

	dst = cubgame->ad[1] + ((j * cubgame->line_length[0])
			+ i * (cubgame->bits_per_pixel[0] / 8));
	*(unsigned int *)dst = c;
}

void	minimap_renders(t_cubd *cubgame, int x, int y, int k)
{
	int	j;
	int	i;

	i = 0;
	while (i <= cubgame->w_screen / 50)
	{
		j = 0;
		while (j <= cubgame->h_screen / 50)
		{
			if (i == 0 || j == 0)
				pixel_set_unset_s_h1(cubgame, i + x * cubgame->w_screen / 50,
					j + y * cubgame->h_screen / 50, 0x0FF000000);
			else
				pixel_set_unset_s_h1(cubgame, i + x * cubgame->w_screen / 50,
					j + y * cubgame->h_screen / 50, k);
			j++;
		}
		i++;
	}
}

void	horizontal_rending(t_cubd *cubgame, int x, int y, int clr)
{
	char	*dst;

	dst = cubgame->ad[1] + ((y * cubgame->line_length[0])
			+ x * (cubgame->bits_per_pixel[0] / 8));
	*(unsigned int *)dst = clr;
}

void	to_player_start_init_fo_norm(t_cubd *cubgame, double x, double y)
{
	double	j;
	double	i;

	i = 0.5 - cubgame->w_screen / 250;
	while (i <= cubgame->w_screen / 250)
	{
		j = 0.5 - cubgame->h_screen / 250;
		while (j <= cubgame->w_screen / 250)
		{
			horizontal_rending(cubgame, i + x * cubgame->w_screen / 50,
				j + y * cubgame->h_screen / 50, 0xff110211);
			j++;
		}
		i++;
	}
}

void	to_player_start_init(t_cubd *cubgame)
{
	double	x;
	double	y;

	if (cubgame->px < 5)
		x = cubgame->px;
	else if (cubgame->width - cubgame->px < 5)
		x = 10 - (cubgame->width - cubgame->px);
	else
		x = 4 + (cubgame->px - (int)cubgame->px);
	if (cubgame->py < 5)
		y = cubgame->py;
	else if (cubgame->height - cubgame->py < 5)
		y = 10 - (cubgame->height - cubgame->py);
	else
		y = 5 + (cubgame->py - (int)cubgame->py);
	to_player_start_init_fo_norm(cubgame, x, y);
}
