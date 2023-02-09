/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:05:35 by hvardany          #+#    #+#             */
/*   Updated: 2023/02/09 23:05:37 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_format(char *av)
{
	char	*n;
	int		i;

	n = ".cub";
	i = 0;
	while (*av && ft_strlen(av) > 4)
		av++;
	if (!av || *av == '\0')
	{
		my_print("ERROR :format map is invalid\n");
		return (1);
	}
	while (av && *av && i < 4)
	{
		if (*av++ != n[i])
		{
			my_print("ERROR :format map is invalid\n");
			return (1);
		}
		i++;
	}
	return (0);
}

char	*gnl(int fd)
{
	int		i;
	int		rd;
	char	character;
	char	*buffer;

	i = 0;
	rd = 0;
	buffer = malloc(10000);
	rd = read(fd, &character, 1);
	while (rd > 0)
	{
		buffer[i++] = character;
		if (character == '\n')
			break ;
		rd = read(fd, &character, 1);
	}
	if ((!buffer[i - 1] && !rd) || rd == -1)
	{
		free(buffer);
		return (0);
	}
	buffer[i] = '\0';
	return (buffer);
}

void	map_read(t_cubd	*cubgame, int fd)
{
	int	i;

	i = 0;
	while (cubgame->line[i] == ' ' || cubgame->line[i] == '\t')
		i++;
	if (cubgame->line[i] == 'N' && cubgame->line[i + 1] == 'O')
		ft_texture(cubgame, cubgame->line + i + 2, 'N');
	else if (cubgame->line[i] == 'S' && cubgame->line[i + 1] == 'O')
		ft_texture(cubgame, cubgame->line + i + 2, 'S');
	else if (cubgame->line[i] == 'W' && cubgame->line[i + 1] == 'E')
		ft_texture(cubgame, cubgame->line + i + 2, 'W');
	else if (cubgame->line[i] == 'E' && cubgame->line[i + 1] == 'A')
		ft_texture(cubgame, cubgame->line + i + 2, 'E');
	else if (cubgame->line[i] == 'C' && cubgame->line[i + 1] == ' ')
		floor_or_ceiling(cubgame, cubgame->line + i + 1, 'C');
	else if (cubgame->line[i] == 'F' && cubgame->line[i + 1] == ' ')
		floor_or_ceiling(cubgame, cubgame->line + i + 1, 'F');
	else if (cubgame->line[i] == '1')
		map_one(cubgame, fd);
	else if (cubgame->line[i] && cubgame->line[i] != '\n')
		exit_game(cubgame, "ERROR: map\n");
}

int	check_read_map(char *av, t_cubd	*cubgame)
{
	int	fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		exit_game(cubgame, "ERROR: File don't can read\n");
	cubgame->line = gnl(fd);
	if (!cubgame->line)
		exit_game(cubgame, "ERROR : map is invalid\n");
	while (cubgame->line)
	{
		map_read(cubgame, fd);
		if (!cubgame->line)
			break ;
		free(cubgame->line);
		cubgame->line = gnl(fd);
	}
	width_and_height_check(cubgame);
	close(fd);
	return (0);
}

int	check_map(char *av, t_cubd *cubgame)
{
	if (check_format(av) == 1)
		return (1);
	if (check_read_map(av, cubgame))
		return (1);
	return (0);
}
