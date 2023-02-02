#include "../cub3d.h"

void	set_nol(int i, int j, t_cubd *cubgame, char c)
{
	char	*s;
	t_list	*g;

	g = cubgame->grafic;
	while (j-- > 0)
		g = g->next;
	s = g->content;
	printf("%s\n", s);
	s[i] = c;
}

char	s_read(int i, int j, t_cubd *cubgame)
{
	t_list	*map;
	char	*s;

	if (i < 0 || j < 0 || i >= cubgame->width || j >= cubgame->height)
		return (' ');
	map = cubgame->grafic;
	while (j > 0)
	{
		j--;
		map = map->next;
	}
	s = map->content;
	return (s[i]);
}
// {
// 	t_list	*g;
// 	char	*s1;

// 	if (i >= 0 && j >= 0 && i < cubgame->width && j < cubgame->height)
// 	{
// 		g = cubgame->grafic;
// 		while (j-- > 0)
// 			g = g->next;
// 		s1 = (char *)g->content;
// 		*s = s1[i];
// 	}
// 	else
// 		*s = ' ';
// }

void	func_w(t_cubd	*cubgame)
{
	int		j;
	int		i;
	char	s;

	i = cubgame->px + (cubgame->dx * 0.2);
	j = cubgame->py + (cubgame->dy  * 0.2);
	s = s_read(i, j, cubgame);
	if (s != '0' && s != 'K')
		return ;
	if (s == 'K')
	{
		cubgame->symbol = '1';
		cubgame->sprite = '0';
		set_nol(i, j, cubgame, '0');
	}
	cubgame->px += (cubgame->dx * 0.1);
	cubgame->py += (cubgame->dy * 0.1);
	if (cubgame->steps)
		cubgame->steps += 1;
}

void	func_a(t_cubd	*cubgame)
{
	int		j;
	int		i;
	char	s;

	i = cubgame->px + (cubgame->dy / 5);
	j = cubgame->py - (cubgame->dx / 5);
	s = s_read(i, j, cubgame);
	if (s != '0' && s != 'K')
		return ;
	if (s == 'K')
	{
		cubgame->symbol = '1';
		cubgame->sprite = '0';
		set_nol(i, j, cubgame, '0');
	}
	cubgame->px = i;
	cubgame->py = j;
	cubgame->steps++;
}

void	func_s(t_cubd	*cubgame)
{
	int		j;
	int		i;
	char	s;

	i = cubgame->px - (cubgame->dy / 5);
	j = cubgame->py - (cubgame->dx / 5);
	s = s_read(i, j, cubgame);
	if (s != '0' && s != 'K')
		return ;
	if (s == 'K')
	{
		cubgame->symbol = '1';
		cubgame->sprite = '0';
		set_nol(i, j, cubgame, '0');
	}
	cubgame->px = i;
	cubgame->py = j;
	cubgame->steps++;
}

void	func_d(t_cubd	*cubgame)
{
	int		j;
	int		i;
	char	s;

	i = cubgame->px - (cubgame->dy / 5);
	j = cubgame->py + (cubgame->dx / 5);
	s = s_read(i, j, cubgame);
	if (s != '0' && s != 'K')
		return ;
	if (s == 'K')
	{
		cubgame->symbol = '1';
		cubgame->sprite = '0';
		set_nol(i, j, cubgame, '0');
	}
	cubgame->px = i;
	cubgame->py = j;
	cubgame->steps++;
}

void	func_open_dor(t_cubd	*cubgame, int i, int j, char s)
{
	char	*str;
	t_list	*g;

	g = cubgame->grafic;
	cubgame->dor_i = i;
	cubgame->dor_j = j;
	while (i-- > 0)
		g = g->next;
	str = g->content;
	str[j] = s;
	cubgame->flag_dor_open = '1';
	cubgame->steps = 1;
}

void	func_closs_dor1(t_cubd	*cubgame, int i, int j, char s)
{
	int	a;
	int	b;
	t_list	*g;
	char	*str;

	a = (int) cubgame->px;
	b = (int) cubgame->py;
	if (cubgame->dor_j != j && cubgame->flag_dor_open == '1')
	{
		cubgame->flag_dor_open = '0';
		while (i-- > 0)
			g = g->next;
		str = g->content;
		str[j] = s;
	}
}

void	func_closs_dor(t_cubd	*cubgame, int i, int j, char s)
{
	int	a;
	int	b;
	t_list	*g;
	char	*str;

	a = (int) cubgame->px;
	b = (int) cubgame->py;
	g = cubgame->grafic;
	if (a == i && b == j && cubgame->symbol == '1')
	{
		if (cubgame->dor_i != a && cubgame->flag_dor_open == '1')
		{
			cubgame->flag_dor_open = '0';
			while (i-- > 0)
				g = g->next;
			str = g->content;
			str[j] = s;
		}
		else
			func_closs_dor1(cubgame, i, j, s);
	}
}

void	func_e(t_cubd	*cubgame)
{
	int		j;
	int		i;
	char	s;

	i = cubgame->px + (cubgame->dy / 5);
	j = cubgame->py + (cubgame->dx / 5);
	s = s_read(i, j, cubgame);
	if (s == 'D' && cubgame->symbol == '1')
		func_open_dor(cubgame, i, j, s);
	else
		func_closs_dor(cubgame, i, j, s);
}

void	func_l(t_cubd	*cubgame)
{
	cubgame->pozition = cubgame->pozition + 5;
	if (cubgame->pozition >= 360)
		cubgame->pozition = cubgame->pozition - 360;
	cubgame->dx = cos(cubgame->pozition * 3.1415 / 180);
	cubgame->dy = sin(cubgame->pozition * 3.1415 / 180);
}

void	key_l_r(t_cubd	*cubgame, int keyx)
{
	if (keyx == 123)
	{
		cubgame->pozition = cubgame->pozition + 5;
		if (cubgame->pozition >= 360)
			cubgame->pozition = cubgame->pozition - 360;
		cubgame->dx = cos(cubgame->pozition * 3.1415 / 180);
		cubgame->dy = sin(cubgame->pozition * 3.1415 / 180);
	}
	else if (keyx == 124)
	{
		cubgame->pozition = cubgame->pozition - 5;
		if (cubgame->pozition < 0)
			cubgame->pozition = cubgame->pozition + 360;
		cubgame->dx = cos(cubgame->pozition * 3.1415 / 180);
		cubgame->dy = sin(cubgame->pozition * 3.1415 / 180);
	}
}

int	key(t_cubd	*cubgame, int keyx)
{
	printf("key\n");
	if (keyx == 13)
		func_w(cubgame);
	else if (keyx == 1)
		func_s(cubgame);
	else if (keyx == 0)
		func_a(cubgame);
	else if (keyx == 2)
		func_d(cubgame);
	else if (keyx == 53)
		exit_and_distroy(cubgame);
	else if (keyx == 14)
		func_e(cubgame);
	else 
		key_l_r(cubgame, keyx);
	return (0);
}