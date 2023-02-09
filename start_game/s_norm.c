/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_norm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:09:30 by hvardany          #+#    #+#             */
/*   Updated: 2023/02/09 23:09:33 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	dx_dy(t_cubd	*cubgame)
{
	cubgame->dx = cos(radian(cubgame->pozition));
	cubgame->dy = -1 * sin(radian(cubgame->pozition));
}
