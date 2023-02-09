/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:15:05 by ergrigor          #+#    #+#             */
/*   Updated: 2023/02/09 23:15:06 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	vertical_s_d_r_norm(t_cubd *cubgame, char s)
{
	cubgame->dis_t = cos(radian(cubgame->bonus.routa))
		* (cubgame->bonus.r_x - cubgame->bonus.px)
		- sin(radian(cubgame->bonus.routa))
		* (cubgame->bonus.r_y - cubgame->bonus.py);
	cubgame->zeros = cubgame->bonus.z;
	if (s == 'D')
		cubgame->zeros = 6;
	cubgame->bonus.h_line = cubgame->width;
}

void	game_drow2_vertical(t_cubd *cubgame)
{
	int		x;
	int		y;
	char	s;

	while (cubgame->bonus.h_line < cubgame->width)
	{
		x = (int)cubgame->bonus.r_x >> 6;
		y = (int)cubgame->bonus.r_y >> 6;
		s = s_read(x, y, cubgame);
		if (s == '1' || s == 'D')
			vertical_s_d_r_norm(cubgame, s);
		else
		{
			cubgame->bonus.r_x = cubgame->bonus.r_x + cubgame->bonus.x_o;
			cubgame->bonus.r_y = cubgame->bonus.r_y + cubgame->bonus.y_o;
			cubgame->bonus.h_line = cubgame->bonus.h_line + 1;
		}
	}
	cubgame->bonus.v_x = cubgame->bonus.r_x;
	cubgame->bonus.v_y = cubgame->bonus.r_y;
}

void	pixel_put(t_cubd *cubgame, int y, int clr)
{
	char	*dst;

	dst = cubgame->ad[1] + ((y * cubgame->line_length[1]) + cubgame->all_i
			* (cubgame->bits_per_pixel[1] / 8));
	*(unsigned int *)dst = clr;
}

void	put_sprite(t_cubd *cubgame, int y)
{
	char	*dst;
	int		i;
	int		j;

	i = (int)cubgame->t_x;
	j = (int)cubgame->t_y;
	if (cubgame->sprite_st == '1')
		dst = cubgame->ad[7] + ((j * cubgame->line_length[7])
				+ i * (cubgame->bits_per_pixel[7] / 8));
	else
		dst = cubgame->ad[8] + ((j * cubgame->line_length[8])
				+ i * (cubgame->bits_per_pixel[8] / 8));
	if (*(unsigned int *)dst != 0x000FF00FF)
		pixel_put(cubgame, y, *(unsigned int *)dst);
}
