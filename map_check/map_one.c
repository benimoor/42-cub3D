#include "../cub3d.h"

int player(char *str, t_cubd *cubgame)
{
	int i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
	{
		if (str[i] == 'S' || str[i] == 'N'
			|| str[i] == 'E' || str[i] == 'W')
		{
			if (cubgame->flag == 1)
				exit_game(cubgame, "ERROR: invalid map double player\n");
			cubgame->flag = 1;
			cubgame->game_player = str[i];
			cubgame->px = i + 0.5;
			cubgame->py = cubgame->player_h + 0.5;
			str[i] = '0';
		}
		else if (str[i] && (str[i] != 32 && str[i] != '1'
			&& str[i] != '0' && str[i] != ' '))
				exit_game(cubgame, "ERROR: map invalid\n");
		i++;
	}
	return (i);
}

void	frst_or_last_line(char *s, t_cubd *cubgame)
{
	int	i;

	i = 0;
	while (s[i] && s[i] == ' ')
		i++;
	if (s[i] != '1' && s[i])
		exit_game(cubgame, "Error:  invalid map\n");
	while (s[i] == ' ' || s[i] == '1')
		i++;
	if (s[i] && s[i] != '\n')
		exit_game(cubgame, "Error:  invalid map\n");
}

void	if_map_line_valid(t_cubd *cubgame, char	*str1, char *str2, char *str3)
{
	int	i;

	i = 0;
	while (str2[i] && str2[i] == 32)
		i++;
	if (str2[i] != '\n' && str2[i] != '1' && str2[i])
		exit_game(cubgame, "ERROR: invalid map");
	while (str2 && str2[i] && str2[i] != '\n')
	{
		while (str2[i] && (str2[i] == 32 || str2[i] == '1'))
			i++;
		if (str2[i] && str2[i] != '\n')
		{
			cubgame->i = i;
			check_zero_around(cubgame, str1, str2, str3);
			i++;
		}
	}
}
void	check_have_value(t_cubd *cubgame)
{
	if (!cubgame->game_player)
		exit_game(cubgame,"ERROR: map not value\n");
	if (!cubgame->no || !cubgame->we || !cubgame->so || !cubgame->ea)
		exit_game(cubgame,"ERROR: not value\n");
	if (cubgame->c[0] < 0 || cubgame->c[1] < 0 || cubgame->c[2] < 0)
		exit_game(cubgame,"ERROR: value RGB\n");
	if (cubgame->f[0] < 0 || cubgame->f[1] < 0 || cubgame->f[2] < 0)
		exit_game(cubgame,"ERROR: value RGB\n");
	if (cubgame->flag != 1)
		exit_game(cubgame,"ERROR: not player\n");
	player_focused(cubgame);
}

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
	while (l_1)
	{
		if (l == cubgame->grafic)
			frst_or_last_line(l->content, cubgame);
		if (l_2 == NULL)
		{
			frst_or_last_line(l_1->content, cubgame);
			check_have_value(cubgame);
			return ;
		}
		if_map_line_valid(cubgame, l->content, l_1->content, l_2->content);
		l = l->next;
		l_1 = l_1->next;
		l_2 = l_2->next;
		if (cubgame->symbol == '0')
			cubgame->keypy++;
	}
}

void	map_one_norm(t_cubd *cubgame, int fd, int i)
{
	i = player(cubgame->line, cubgame);
	if (i > cubgame->width)
		cubgame->width = i;
	ft_lstadd_back(&cubgame->grafic, ft_lstnew(ft_strtrim(cubgame->line, "\n")));
	free(cubgame->line);
	cubgame->line = 0;
	cubgame->line = gnl(fd);
	cubgame->height++;
}

void    map_one(t_cubd *cubgame, int fd)
{
	int i;

	if (cubgame->flag_one == 1)
		exit_game(cubgame, "ERROR: invalid map\n");
	cubgame->flag_one = 1;
	cubgame->symbol = '0';
	while (cubgame->line)
	{
		i = 0;
		while (cubgame->line && cubgame->line[i] == 32)
			i++;
		if (!cubgame->line[i])
		{
			free(cubgame->line);
			cubgame->line = NULL;
			break ;
		}
		map_one_norm(cubgame, fd, i);
	}
	if_list_valid(cubgame);
}