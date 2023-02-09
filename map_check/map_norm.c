/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_norm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:05:46 by hvardany          #+#    #+#             */
/*   Updated: 2023/02/09 23:05:48 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	if_list_valid(t_cubd *cubgame)
{
	t_list	*l;
	t_list	*l_1;
	t_list	*l_2;

	l = cubgame->grafic;
	l_1 = cubgame->grafic->next;
	if (!l_1 || !l)
		exit_game(cubgame, "ERROR: invalid map\n");
	l_2 = l_1->next;
	if (!l_2)
		exit_game(cubgame, "ERROR: invalid map\n");
	list_norm(cubgame, l, l_1, l_2);
}

void	map_one_norm(t_cubd *cubgame, int fd, int i)
{
	i = player(cubgame->line, cubgame);
	if (i > cubgame->width)
		cubgame->width = i;
	ft_lstadd_back(&cubgame->grafic, ft_lstnew(ft_strtrim(cubgame->line, "\n")));
	free(cubgame->line);
	cubgame->line = NULL;
	cubgame->line = gnl(fd);
	cubgame->height++;
}

void	map_one(t_cubd *cubgame, int fd)
{
	int	i;

	if (cubgame->flag_one == 1)
		exit_game(cubgame, "ERROR: invalid map\n");
	cubgame->flag_one = 1;
	while (cubgame->line)
	{
		i = 0;
		while (cubgame->line && cubgame->line[i] == 32)
			i++;
		if (!cubgame->line[i] || cubgame->line[i] == '\n')
		{
			free(cubgame->line);
			cubgame->line = NULL;
			break ;
		}
		map_one_norm(cubgame, fd, i);
	}
	if_list_valid(cubgame);
}
