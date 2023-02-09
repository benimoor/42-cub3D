/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:01:40 by hvardany          #+#    #+#             */
/*   Updated: 2023/02/09 23:06:34 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_all(t_cubd *cubgame)
{
	free(cubgame->ea);
	free(cubgame->line);
	free(cubgame->no);
	free(cubgame->so);
}

void	exit_game(t_cubd	*cubgame, char *str)
{
	my_print(str);
	free_all(cubgame);
	exit (1);
}

int	exit_and_distroy(t_cubd	*cubgame)
{
	free_all(cubgame);
	mlx_destroy_window(cubgame->init_mlx, cubgame->window);
	exit (0);
	return (0);
}

void	exit_and_distroy1(t_cubd	*cubgame, char *str)
{
	my_print(str);
	free_all(cubgame);
	mlx_destroy_window(cubgame->init_mlx, cubgame->window);
	exit (1);
}
