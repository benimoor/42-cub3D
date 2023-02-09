/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_tts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:15:11 by ergrigor          #+#    #+#             */
/*   Updated: 2023/02/09 23:15:12 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	render_minimap(t_cubd *cubgame)
{
	if (cubgame->minimap)
		mlx_destroy_image(cubgame->init_mlx, cubgame->minimap);
	cubgame->minimap = mlx_new_image(cubgame->init_mlx,
			cubgame->w_screen / 5, cubgame->h_screen / 5);
	cubgame->ad[1] = mlx_get_data_addr(cubgame->minimap,
			&cubgame->bits_per_pixel[0], &cubgame->line_length[0],
			&cubgame->endian[0]);
}

void	rener_mip(t_list *m, t_cubd *cubgame)
{
	double	y;
	double	x;

	render_minimap(cubgame);
	y = 0;
	while (cubgame->height > 11 && cubgame->py > y + 6
		&& cubgame->height > y + 10)
	{
		m = m->next;
		y++;
	}
	if (cubgame->width < 11 || cubgame->px <= 4)
		x = 0;
	else if (cubgame->width - cubgame->px <= 6)
		x = cubgame->width - 10;
	else
		x = cubgame->px - 4;
	minimap(m, cubgame, x);
	mlx_put_image_to_window(cubgame->init_mlx, cubgame->window,
		cubgame->minimap, 0, 0);
}

void	asd_asd_ke_r(t_cubd *cubgame)
{
	cubgame->pozition -= 5;
	cubgame->pozition = angl(cubgame->pozition);
	cubgame->dx = cos(radian(cubgame->pozition));
	cubgame->dy = -1 * sin(radian(cubgame->pozition));
}

void	symbol_tts(int i, int j, t_cubd *cubgame, char c)
{
	char	*str;
	t_list	*m;

	if (i < 0 || j < 0)
		return ;
	m = cubgame->grafic;
	while (j > 0)
	{
		j--;
		m = m->next;
	}
	str = m->content;
	str[i] = c;
}

void	asd_asd_ke_l(t_cubd *cubgame)
{
	cubgame->pozition += 5;
	cubgame->pozition = angl(cubgame->pozition);
	cubgame->dx = cos(radian(cubgame->pozition));
	cubgame->dy = -1 * sin(radian(cubgame->pozition));
}
