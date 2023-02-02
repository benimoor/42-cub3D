#include "cub3d.h"
void	func_null1(t_cubd *cubgame)
{
	cubgame->c[0] = -1;
	cubgame->c[1] = -1;
	cubgame->c[2] = -1;
	cubgame->f[0] = -1;
	cubgame->f[1] = -1;
	cubgame->f[2] = -1;
	cubgame->game_player = 0;
	cubgame->timer = 0;
}
void	func_null(t_cubd *cubgame)
{
	int i;
	i = 0;
	cubgame->ea = NULL;
	cubgame->line = NULL;
	cubgame->dx = 0;
	cubgame->dy = 0;
	cubgame->no = NULL;
	cubgame->so = NULL;
	cubgame->grafic = NULL;
	cubgame->px = 0;
	cubgame->py = 0;
	cubgame->s = 0;
	cubgame->w = 0;
	cubgame->x = 0;
	cubgame->y = 0;
	cubgame->flag = 0;
	cubgame->player_h = 0;
	cubgame->height = 0;
	cubgame->width = 0;
	cubgame->have_zerro = 0;
	cubgame->keypx = 0;
	cubgame->keypy = 1;
	cubgame->flag_one = 0;
	cubgame->x_1 = 0;
	cubgame->h_screen = 1000;
	cubgame->w_screen = 1000;
	cubgame->step_flag = 0;
	cubgame->a_l = 60.0 / cubgame->w_screen;
	cubgame->minimap = NULL;
	cubgame->init_mlx = NULL;
	cubgame->dur = 0;
	cubgame->key1 = 0;
	cubgame->key2 = 0;
	cubgame->window = 0;
	cubgame->create_fon = 0;
	while (i < 9)
	{
		cubgame->ad[i] = NULL;
		i++;
	}
	func_null1(cubgame);
}

void	check_valid_value(t_cubd *cubgame)
{
	if (!cubgame->h_screen || !cubgame->w_screen || !cubgame->so || !cubgame->no
		|| !cubgame->we || !cubgame->ea)
	exit_game(cubgame, "ERROR: map \n");
}

int main(int argc, char **argv)
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
	printf("ok  ==  %s\n",  argv[0]);
}	