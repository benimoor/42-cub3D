/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor < ergrigor@student.42yerevan.am > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:15:21 by ergrigor          #+#    #+#             */
/*   Updated: 2023/02/09 23:15:25 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	func_cos_vert_plus(t_cubd *cubgame)
{
	cubgame->bonus.z = 5;
	cubgame->bonus.r_x = (((int)cubgame->bonus.px >> 6) << 6) + 64;
	cubgame->bonus.r_y = (cubgame->bonus.px - cubgame->bonus.r_x)
		* cubgame->bonus.tan_ra + cubgame->bonus.py;
	cubgame->bonus.x_o = 64;
	cubgame->bonus.y_o = -64 * cubgame->bonus.tan_ra;
}

void	func_cos_vert_minus(t_cubd *cubgame)
{
	cubgame->bonus.z = 4;
	cubgame->bonus.r_x = (((int)cubgame->bonus.px >> 6) << 6) - 0.0001;
	cubgame->bonus.r_y = (cubgame->bonus.px - cubgame->bonus.r_x)
		* cubgame->bonus.tan_ra + cubgame->bonus.py;
	cubgame->bonus.x_o = -64;
	cubgame->bonus.y_o = 64 * cubgame->bonus.tan_ra;
}

void	func_cos_vert_noll(t_cubd *cubgame)
{
	cubgame->bonus.h_line = cubgame->width;
	cubgame->bonus.r_x = cubgame->bonus.px;
	cubgame->bonus.r_y = cubgame->bonus.py;
}

void	vertical_start(t_cubd *cubgame)
{
	cubgame->bonus.tan_ra = tan(radian(cubgame->bonus.routa));
	cubgame->bonus.h_line = 0;
	if (cos(radian(cubgame->bonus.routa)) < -0.0001)
		func_cos_vert_minus(cubgame);
	else if (cos(radian(cubgame->bonus.routa)) > 0.0001)
		func_cos_vert_plus(cubgame);
	else if (cos(radian(cubgame->bonus.routa)) == 0)
		func_cos_vert_noll(cubgame);
	game_drow2_vertical(cubgame);
}
