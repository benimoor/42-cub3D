/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture_pixel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:15:08 by ergrigor          #+#    #+#             */
/*   Updated: 2023/02/09 23:15:09 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	pixel_set_11(t_cubd *cubgame, int i, int c)
{
	char	*ds_t;

	ds_t = cubgame->ad[1] + ((i * cubgame->line_length[1])
			+ cubgame->all_i * (cubgame->bits_per_pixel[1] / 8));
	*(unsigned int *)ds_t = c;
}

void	textur_set(t_cubd *cubgame, int i, int k)
{
	char	*ds_t;
	int		x;
	int		j;

	if (cubgame->line_len == 0)
		return ;
	x = cubgame->bonus.r_a_y;
	k += cubgame->step_flag;
	j = (k << 6) / cubgame->line_len ;
	ds_t = cubgame->ad[cubgame->zeros]
		+ ((j * cubgame->line_length[cubgame->zeros]))
		+ x * (cubgame->bits_per_pixel[cubgame->zeros] / 8);
	pixel_set_11(cubgame, i, *(unsigned int *)ds_t);
}

void	pixel_set(t_cubd *cubgame, int i, int flag)
{
	int		x;
	char	*ds_t;

	ds_t = cubgame->ad[1] + ((i * cubgame->line_length[1])
			+ cubgame->all_i * (cubgame->bits_per_pixel[1] / 8));
	if (flag == 0)
	{
		x = t_r_g(0, cubgame->c[0], cubgame->c[1], cubgame->c[2]);
	}
	else
		x = t_r_g(0, cubgame->f[0], cubgame->f[1], cubgame->f[2]);
	*(unsigned int *)ds_t = x;
}

void	my_mlx_pixel_put(t_cubd *game, int x, int y, int clr)
{
	char	*dst;

	dst = game->ad[1] + ((y * game->line_length[1]) + x
			* (game->bits_per_pixel[1] / 8));
	*(unsigned int *)dst = clr;
}

void	put_texture_pixel(t_cubd *cubgame, int x, int y, int k)
{
	char	*dst;
	int		i;
	int		j;

	if (cubgame->line_len == 0)
		return ;
	i = cubgame->bonus.r_a_y;
	k = k + cubgame->step_flag;
	j = (k << 6) / cubgame->line_len;
	dst = cubgame->ad[cubgame->zeros]
		+ ((j * cubgame->line_length[cubgame->zeros])
			+ i * (cubgame->bits_per_pixel[cubgame->zeros] / 8));
	my_mlx_pixel_put(cubgame, x, y, *(unsigned int *)dst);
}
