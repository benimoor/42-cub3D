/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ero_norm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:14:54 by ergrigor          #+#    #+#             */
/*   Updated: 2023/02/09 23:14:55 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	sprite_drov(t_cubd *cubgame)
{
	double	y;

	if (cubgame->sprite == '0')
		return ;
	if (cubgame->all_i >= (cubgame->slayd_x - cubgame->spr_scale / 2)
		&& cubgame->all_i < (cubgame->slayd_x + cubgame->spr_scale / 2)
		&& cubgame->b > 0 && cubgame->b < cubgame->dis_t)
	{
		cubgame->t_y = 62;
		y = 0;
		while (y < cubgame->spr_scale)
		{
			put_sprite(cubgame, cubgame->slayd_y - y);
			cubgame->t_y -= cubgame->bonus.t_y_step;
			if (cubgame->t_y < 0)
				cubgame->t_y = 0;
			y++;
		}
		cubgame->t_x += cubgame->bonus.t_x_step;
	}
}

void	vertikal_norm_two(t_cubd *cubgame)
{
	line_on_map_draw(cubgame);
	sprite_drov(cubgame);
	cubgame->bonus.routa = angl(cubgame->bonus.routa - cubgame->a_l);
}

void	vertical(t_cubd *cubgame)
{
	int	i;

	i = 0;
	cubgame->bonus.routa = angl(cubgame->pozition + 30);
	cubgame->bonus.px = cubgame->px * 64;
	cubgame->bonus.py = cubgame->py * 64;
	while (i < cubgame->w_screen)
	{
		cubgame->dis_t = 1000000;
		cubgame->all_i = i;
		vertical_start(cubgame);
		horizontal(cubgame);
		cubgame->dis_t *= cos(radian(angl(cubgame->pozition
						- cubgame->bonus.routa)));
		if (cubgame->zeros > 3 && cubgame->zeros != 6)
			cubgame->bonus.r_a_y = (int)(cubgame->bonus.v_y) % 64;
		else
			cubgame->bonus.r_a_y = (int)(cubgame->bonus.r_x) % 64;
		vertikal_norm_two(cubgame);
		i++;
	}
}

int	t_r_g(int t1, int t2, int t3, int t4)
{
	return (t1 << 24 | t2 << 16 | t3 << 8 | t4);
}
