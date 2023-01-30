#include "../cub3d.h"

void	player_focused(t_cubd *cubgame)
{
	if (cubgame->game_player == 'E')
		cubgame->pozition = 0;
	else if (cubgame->game_player == 'N')
		cubgame->pozition = 90;
	else if (cubgame->game_player == 'W')
		cubgame->pozition = 180;
	else if (cubgame->game_player == 'S')
		cubgame->pozition = 270;
}

double	radian(double degry)
{
	double	d;

	d = degry * 3.14159 / 180;
	return (d);
}