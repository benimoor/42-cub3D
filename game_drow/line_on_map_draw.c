/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_on_map_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:15:01 by ergrigor          #+#    #+#             */
/*   Updated: 2023/02/09 23:15:02 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	line_on_map_draw1(t_cubd *cubgame, int i, int h, int f)
{
	int	k;
	int	j;

	k = -1;
	j = 0;
	(void)i;
	while (j < cubgame->h_screen)
	{
		if (j < f)
		{
			pixel_set(cubgame, j, 0);
		}
		else if (j > h + f)
		{
			pixel_set(cubgame, j, 1);
		}
		else
			textur_set(cubgame, j, k++);
		j++;
	}
}

void	draw_line_2(t_cubd *cubgame, int i, int lineh, int lineoff)
{
	int	k;
	int	y;

	k = -1;
	y = 0;
	while (y < cubgame->h_screen)
	{
		if (y < lineoff)
			my_mlx_pixel_put(cubgame, i, y,
				create_trgb(0, cubgame->c[0], cubgame->c[1], cubgame->c[2]));
		else if (y > lineh + lineoff)
			my_mlx_pixel_put(cubgame, i, y,
				create_trgb(0, cubgame->f[0], cubgame->f[1], cubgame->f[2]));
		else
			put_texture_pixel(cubgame, i, y, k++);
		y++;
	}
}

void	line_on_map_draw(t_cubd *cubgame)
{
	int	h;
	int	f;

	h = (cubgame->h_screen << 5) / cubgame->dis_t;
	cubgame->step_flag = 0;
	cubgame->line_len = h;
	if (h > cubgame->h_screen)
	{
		cubgame->step_flag = ((h - cubgame->h_screen) >> 1);
		h = cubgame->h_screen;
	}
	f = (cubgame->h_screen - h) >> 1;
	line_on_map_draw1(cubgame, cubgame->all_i, h, f);
}
