/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:01:07 by hvardany          #+#    #+#             */
/*   Updated: 2023/02/09 23:01:10 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_valid_value(t_cubd *cubgame)
{
	if (!cubgame->h_screen || !cubgame->w_screen || !cubgame->so || !cubgame->no
		|| !cubgame->we || !cubgame->ea)
		exit_game(cubgame, "ERROR: map \n");
}

int	main(int argc, char **argv)
{
	t_cubd	cubgame;

	if (argc != 2)
	{
		my_print("ERROR!\n");
		return (1);
	}
	func_null(&cubgame);
	if (check_map(argv[1], &cubgame))
		return (1);
	check_valid_value(&cubgame);
	start_draw_game(&cubgame);
}
