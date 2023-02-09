/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizon_pozition_y_nol.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:08:00 by hvardany          #+#    #+#             */
/*   Updated: 2023/02/09 23:08:57 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	horizon_pozition_y_plus(t_cubd *cubgame)
{
	cubgame->bonus.z_h = 2;
	cubgame->bonus.r_y = (((int)cubgame->bonus.py >> 6) << 6) - 0.0001;
	cubgame->bonus.r_x = (cubgame->bonus.py - cubgame->bonus.r_y)
		* cubgame->bonus.atan_ra + cubgame->bonus.px;
	cubgame->bonus.y_o = -64;
	cubgame->bonus.x_o = 64 * cubgame->bonus.atan_ra;
}

void	horizon_pozition_y_minus(t_cubd *cubgame)
{
	cubgame->bonus.z_h = 3;
	cubgame->bonus.r_y = (((int)cubgame->bonus.py >> 6) << 6) + 64;
	cubgame->bonus.r_x = (cubgame->bonus.py - cubgame->bonus.r_y)
		* cubgame->bonus.atan_ra + cubgame->bonus.px;
	cubgame->bonus.y_o = 64;
	cubgame->bonus.x_o = -64 * cubgame->bonus.atan_ra;
}

void	horizon_pozition_y_nol(t_cubd *cubgame)
{
	cubgame->bonus.h_line = cubgame->height;
	cubgame->bonus.r_x = cubgame->bonus.px;
	cubgame->bonus.r_y = cubgame->bonus.py;
}
