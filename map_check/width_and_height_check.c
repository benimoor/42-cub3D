/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_and_height_check.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:05:24 by hvardany          #+#    #+#             */
/*   Updated: 2023/02/09 23:05:27 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	widht_check(t_cubd *cubgame)
{
	t_list	*l;
	size_t	len;
	char	*s;

	l = cubgame->grafic;
	if (cubgame->width < 10)
		cubgame->width = 10;
	while (l)
	{
		len = ft_strlen(l->content);
		while (len < cubgame->width)
		{
			s = ft_strjoin(l->content, " ");
			free(l->content);
			l->content = s;
			len = ft_strlen(l->content);
		}
		l = l->next;
	}
}

void	height_check(t_cubd *cubgame)
{
	char	*str;
	int		i;
	int		n;
	int		j;
	t_list	*t;

	i = 0;
	n = 0;
	j = 0;
	if (cubgame->height < 10)
	{
		n = 10 - cubgame->height;
		cubgame->height = 0;
	}
	while (i < n)
	{
		str = malloc(sizeof(char) * (cubgame->width + 1));
		j = -1;
		while (++j < cubgame->width)
			str[j] = ' ';
		str[j] = '\0';
		t = ft_lstnew(str);
		ft_lstadd_back(&cubgame->grafic, t);
		i++;
	}
}

void	width_and_height_check(t_cubd *cubgame)
{
	widht_check(cubgame);
	height_check(cubgame);
}
