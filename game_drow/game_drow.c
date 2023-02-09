/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_drow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:14:58 by ergrigor          #+#    #+#             */
/*   Updated: 2023/02/09 23:14:59 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	sprite_for_norm(t_cubd *cubgame)
{
	cubgame->slayd_x = (cubgame->keypx - cubgame->px) * 64;
	cubgame->slayd_y = (cubgame->keypy - cubgame->py) * 64;
	cubgame->bonus.k = 10;
	cubgame->bonus.x_x = cos(radian(cubgame->pozition));
	cubgame->bonus.y_y = sin(radian(cubgame->pozition));
	cubgame->bonus.i = cubgame->slayd_y * cubgame->bonus.x_x
		+ cubgame->slayd_x * cubgame->bonus.y_y;
	cubgame->bonus.j = cubgame->slayd_x * cubgame->bonus.x_x
		- cubgame->slayd_y * cubgame->bonus.y_y;
	cubgame->b = cubgame->bonus.j;
}

double	angl(double t)
{
	if (t >= 360)
		return (t - 360);
	if (t <= -1)
		return (360 + t);
	return (t);
}

void	game_drow1_sprite(t_cubd *cubgame)
{
	if (cubgame->sprite != '0')
	{
		sprite_for_norm(cubgame);
		cubgame->slayd_x = cubgame->bonus.i * 800
			/ cubgame->bonus.j + (cubgame->w_screen / 2);
		cubgame->slayd_y = cubgame->bonus.k * 800
			/ cubgame->bonus.j + (cubgame->h_screen / 2);
		cubgame->bonus.scale = 5 * cubgame->h_screen / cubgame->b;
		if (cubgame->bonus.scale < 0)
			cubgame->bonus.scale = 0;
		else if (cubgame->bonus.scale > cubgame->w_screen / 2)
			cubgame->bonus.scale = cubgame->w_screen / 2;
		cubgame->t_x = 0;
		cubgame->bonus.t_x_step = 63.0 / cubgame->bonus.scale;
		cubgame->bonus.t_y_step = 64.0 / cubgame->bonus.scale;
	}
}

void	minimap(t_list *m, t_cubd *cubgame, double x)
{
	int		i;
	int		j;
	char	*line;

	j = 0;
	while (m && j < 10)
	{
		line = m->content;
		i = 0;
		while (line[(int)x + i] && i < 10)
		{
			if (line[(int)x + i] == '1')
				minimap_renders(cubgame, i, j, 0x2202f2);
			else if (line[(int)x + i] == 'D')
				minimap_renders(cubgame, i, j, 0x038a30);
			else
				minimap_renders(cubgame, i, j, 0x00000000);
			i++;
		}
		j++;
		m = m->next;
	}
	to_player_start_init(cubgame);
}

void	vertical_and_horizontal_check(t_cubd *cubgame)
{
	vertical(cubgame);
	mlx_put_image_to_window(cubgame->init_mlx, cubgame->window,
		cubgame->create_fon, 0, 0);
	rener_mip(cubgame->grafic, cubgame);
}
