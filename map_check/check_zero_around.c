#include "../cub3d.h"

int	when_have_zerro(char	*str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] == '0')
			return (0);
		i++;
	}
	return (0);
}

void	when_all_zerro(t_cubd *cubgame, char	*str1, char *str2, char *str3)
{
	int	k;

	k = cubgame->i;
	if (str2[k] == '0')
	{
		if (cubgame->symbol == '0' && str1[k] == '0' && str1[k + 1] == '0'
			&& str1[k - 1] == '0' && str2[k] == '0' && str2[k + 1] == '0'
			&& str2[k - 1] == '0' && str3[k] == '0' && str3[k + 1] == '0'
			&& str3[k - 1] == '0')
		{
			cubgame->symbol = '1';
			str2[k] = 'K';
			cubgame->keypx = k;
		}
	}
}

int	char_walid(char str)
{
	if (!str || str == '\n')
		return (1);
	if (str == '1' || str == '0' || str == 'W' || str == 'N'
		|| str == 'S' || str == 'E' || str == 'K' || str == 'D')
		return (1);
	return (0);
}

int	char_walid1(char str)
{
	if (str == '0' || str == 'W' || str == 'N'
		|| str == 'S' || str == 'E' || str == 'K' || str == 'D')
		return (1);
	return (0);
}

void	check_around(t_cubd *cubgame, char	*str1, char *str2, char *str3)
{
	int	k;

	k = cubgame->i;
	if (str2[k] && char_walid1(str2[k]) && !char_walid(str2[k + 1]))
	 	exit_game(cubgame, "ERROR: 1invalid map\n");
	 if (str2[k] && char_walid1(str2[k]) && !char_walid(str2[k - 1]))
	 {
		printf("%c %c %c \n", str2[k-1], str1[k-1], str3[k - 1]);
		exit_game(cubgame, "ERROR: 2invalid map\n");
	 }
	 if (str2[k] && char_walid1(str2[k]) && !char_walid(str1[k + 1]))
	 	exit_game(cubgame, "ERROR: 3invalid map\n");
	 if (str2[k] && char_walid1(str2[k]) && !char_walid(str1[k - 1]))
	 	exit_game(cubgame, "ERROR: 4invalid map\n");
	 if (str2[k] && char_walid1(str2[k]) && !char_walid(str3[k - 1]))
	 	exit_game(cubgame, "ERROR: 5invalid map\n");
	 if (str2[k] && char_walid1(str2[k]) && !char_walid(str3[k + 1]))
	 	exit_game(cubgame, "ERROR: 6invalid map\n");
	if (char_walid1(str2[k]) && (ft_strlen(str1) < (size_t)(k + 1) || ft_strlen(str3) < (size_t)(k + 1)))
		exit_game(cubgame, "ERROR: 7invalid map\n");
}

void	when_around_have_space(t_cubd *cubgame, char	*str1, char *str2, char *str3)
{
	int	k;

	k = cubgame->zeros;
	if (!str2[k] || str2[k] == 32 || !str2[k - 1] || str2[k - 1] == 32
		|| !str2[k + 1] || str2[k + 1] == '\n'
		|| str2[k + 1] == 32 || !str1[k] || str1[k] == 32 || !str1[k - 1]
		|| str1[k - 1] == 32 || !str1[k + 1] || str1[k + 1] == '\n'
		|| str1[k + 1] == 32 || !str3[k] || str3[k] == 32 || !str3[k - 1]
		|| str3[k - 1] == 32 || !str3[k + 1] || str3[k + 1] == '\n'
		|| str3[k + 1] == 32)
	 exit_game(cubgame, "ERROR: 123invalid map\n");
	 check_around(cubgame, str1, str2, str3);
}

void	check_zero_around(t_cubd *cubgame, char	*str1, char *str2, char *str3)
{
	int	k;

	k = cubgame->zeros;
	cubgame->have_zerro = when_have_zerro(str2);
	when_around_have_space(cubgame, str1, str2, str3);
	if (str2[k] == 48 && str2[k + 1] == '1' && str2[k - 1] == '1'
		&& str3[k] == 48 && str1[k] == 48
		&& (str1[k + 1] == '1' || str3[k +1] == '1'))
	str2[k] = 'D';
	else
		when_all_zerro(cubgame, str1, str2, str3);
}