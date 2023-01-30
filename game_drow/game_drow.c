#include "../cub3d.h"

void	sprite_for_norm(t_cubd *cubgame)
{
	cubgame->slayd_x = (cubgame->keypx - cubgame->px) * 64;
	cubgame->slayd_y = (cubgame->keypy - cubgame->py) * 64;
	cubgame->bonus.k = 10;
	cubgame->bonus.x_x = cos(radian(cubgame->pozition));
	cubgame->bonus.y_y = sin(radian(cubgame->pozition));
	cubgame->bonus.i = cubgame->slayd_y * cubgame->bonus.x_x + cubgame->slayd_x * cubgame->bonus.y_y;
	cubgame->bonus.j = cubgame->slayd_x * cubgame->bonus.x_x - cubgame->slayd_y * cubgame->bonus.y_y;
	cubgame->b = cubgame->bonus.j;
}

double	angl(double	t)
{
	if (t >= 360)
		return (360 - t);
	if (t < 0)
		return (306 + t);
	return (t);
}

void	game_drow1_sprite(t_cubd *cubgame)
{
	if (cubgame->sprite != '0')
	{
		sprite_for_norm(cubgame);
		cubgame->slayd_x = cubgame->bonus.i * 800 / cubgame->bonus.j + (cubgame->w_screen / 2);
		cubgame->slayd_y = cubgame->bonus.k * 800 / cubgame->bonus.j + (cubgame->h_screen / 2);
		cubgame->bonus.scale = 5 * cubgame->h_screen / cubgame->b;
		if (cubgame->bonus.scale < 0)
			cubgame->bonus.scale = 0;
		else if (cubgame->bonus.scale > cubgame->w_screen / 2)
			cubgame->bonus.scale = cubgame->w_screen / 2;
		cubgame->t_x = 0;
		cubgame->bonus.t_x_step = 63.0 / cubgame->bonus.scale;
		cubgame->bonus.t_y_step = 64.0 / cubgame->bonus.scale;
	}
	cubgame->bonus.routa = angl(cubgame->pozition + 30);
}

void	func_cos_vert_plus(t_cubd *cubgame)
{
	cubgame->bonus.z = 5;
	cubgame->bonus.r_x = (((int)cubgame->bonus.px >> 6) << 6) + 64;
	cubgame->bonus.r_y = (cubgame->bonus.px - cubgame->bonus.r_x) * cubgame->bonus.tan_ra + cubgame->bonus.py;
	cubgame->bonus.x_o = 64;
	cubgame->bonus.y_o = -64 * cubgame->bonus.tan_ra;
}

void	func_cos_vert_minus(t_cubd *cubgame)
{
	cubgame->bonus.z = 4;
	cubgame->bonus.r_x = (((int)cubgame->bonus.px >> 6) << 6) -0.0001;
	cubgame->bonus.r_y = (cubgame->bonus.px - cubgame->bonus.r_x) * cubgame->bonus.tan_ra + cubgame->bonus.py;
	cubgame->bonus.x_o = -64;
	cubgame->bonus.y_o = 64 * cubgame->bonus.tan_ra;
}

void	func_cos_vert_noll(t_cubd *cubgame)
{
	cubgame->bonus.h_line = cubgame->width;
	cubgame->bonus.r_x = cubgame->bonus.px;
	cubgame->bonus.r_y = cubgame->bonus.py;
}

void	vertical_s_d_r_norm(t_cubd *cubgame, char *s)
{
	cubgame->dis_t = cos(radian(cubgame->bonus.routa)) * (cubgame->bonus.r_x - cubgame->bonus.px)
		- sin(radian(cubgame->bonus.routa)) * (cubgame->bonus.r_y - cubgame->bonus.py);
	cubgame->i = cubgame->bonus.z;
	if (*s == 'D')
		cubgame->i = 6;
	cubgame->bonus.h_line = cubgame->width;
}

void	game_drow2_vertical(t_cubd *cubgame)
{
	int		x;
	int		y;
	char	s;

	while (cubgame->bonus.h_line < cubgame->width)
	{
		x = (int)cubgame->bonus.r_x >> 6;
		y = (int)cubgame->bonus.r_y >> 6;
		s_read(x, y, cubgame, &s);
		if (s == '1' || s == 'D')
			vertical_s_d_r_norm(cubgame, &s);
		else
		{
			cubgame->bonus.r_x = cubgame->bonus.r_x + cubgame->bonus.x_o;
			cubgame->bonus.r_y = cubgame->bonus.r_y + cubgame->bonus.y_o;
			cubgame->bonus.h_line = cubgame->bonus.h_line + 1;
		}
	}
	cubgame->bonus.v_x = cubgame->bonus.r_x;
	cubgame->bonus.v_y = cubgame->bonus.r_y;
}

void	pixel_put(t_cubd *cubgame, int y, int clr)
{
	char	*dst;

	dst = cubgame->ad[1] + ((y * cubgame->line_length[1]) + cubgame->all_i
			* (cubgame->bits_per_pixel[1] / 8));
	*(unsigned int *)dst = clr;
}
void	put_sprite(t_cubd *cubgame, int y)
{
	char	*dst;
	int		i;
	int		j;

	i = (int)cubgame->t_x;
	j = (int)cubgame->t_y;
	if (cubgame->sprite == '1')
		dst = cubgame->ad[7] + ((j * cubgame->line_length[7])
				+ i * (cubgame->bits_per_pixel[7] / 8));
	else
		dst = cubgame->ad[8] + ((j * cubgame->line_length[8])
				+ i * (cubgame->bits_per_pixel[8] / 8));
	if (*(unsigned int *)dst != 0x000FF00FF)
		pixel_put(cubgame, y, *(unsigned int *)dst);
}

void	sprite_drov(t_cubd *cubgame)
{
	double	y;

	if (cubgame->sprite == '0')
		return ;
	if (cubgame->all_i >= (cubgame->slayd_x - cubgame->spr_scale / 2)
		&& cubgame->all_i < (cubgame->slayd_x + cubgame->spr_scale / 2)
		&& cubgame->b > 0 && cubgame->b < cubgame->dis_t)
	{
		cubgame->t_y = 62;
		y = 0;
		while (y < cubgame->spr_scale)
		{
			put_sprite(cubgame, cubgame->slayd_y - y);
			cubgame->t_y -= cubgame->bonus.t_y_step;
			if (cubgame->t_y < 0)
				cubgame->t_y = 0;
			y++;
		}
		cubgame->t_x += cubgame->bonus.t_x_step;
	}
}

void	vertical(t_cubd *cubgame)
{
	int	i;

	i = 0;
	cubgame->bonus.px = cubgame->px * 64;
	cubgame->bonus.py = cubgame->py * 64;
	while (i < cubgame->w_screen)
	{
		cubgame->dis_t = 1000000;
		cubgame->all_i = i;
		cubgame->bonus.tan_ra = tan(radian(cubgame->bonus.routa));
		cubgame->bonus.h_line = 0;
		if (cos(radian(cubgame->bonus.routa)) < -0.0001)
			func_cos_vert_minus(cubgame);
		else if (cos(radian(cubgame->bonus.routa)) > 0.0001)
			func_cos_vert_plus(cubgame);
		else if (cos(radian(cubgame->bonus.routa)) == 0)
			func_cos_vert_noll(cubgame);
		game_drow2_vertical(cubgame);

		horizontal(cubgame);
		sprite_drov(cubgame);
		cubgame->bonus.routa = angl(cubgame->bonus.routa - cubgame->a_l);
		i++;
	}
}

void	horizon_pozition_y_plus(t_cubd *cubgame)
{
	cubgame->bonus.z_h = 2;
	cubgame->bonus.r_y = (((int)cubgame->bonus.py >> 6) << 6) - 0.0001;
	cubgame->bonus.r_x = (cubgame->bonus.py - cubgame->bonus.r_y) * cubgame->bonus.atan_ra + cubgame->bonus.px;
	cubgame->bonus.y_o = -64;
	cubgame->bonus.x_o = 64 * cubgame->bonus.atan_ra;
}

void	horizon_pozition_y_minus(t_cubd *cubgame)
{
	cubgame->bonus.z_h = 3;
	cubgame->bonus.r_y = (((int)cubgame->bonus.px >> 6) << 6) + 64;
	cubgame->bonus.r_x = (cubgame->bonus.py - cubgame->bonus.r_y) * cubgame->bonus.atan_ra + cubgame->bonus.px;
	cubgame->bonus.y_o = 64;
	cubgame->bonus.x_o = -64 * cubgame->bonus.atan_ra;
}

void	horizon_pozition_y_nol(t_cubd *cubgame)
{
	cubgame->bonus.h_line = cubgame->height;
	cubgame->bonus.r_x = cubgame->bonus.px;
	cubgame->bonus.r_y = cubgame->bonus.py;
}

void	horizontal_have_dor(t_cubd *cubgame, char s)
{
	double	des;

	des = cos(radian(cubgame->bonus.routa)) * (cubgame->bonus.r_x - cubgame->bonus.px)
		- sin(radian(cubgame->bonus.routa)) * (cubgame->bonus.r_y - cubgame->bonus.py);
	if (des < cubgame->dis_t)
	{
		cubgame->i = cubgame->bonus.z_h;
		if (s == 'D')
			cubgame->bonus.i = 6;
		cubgame->dis_t = des;
	}
	else
	{
		cubgame->bonus.r_x = cubgame->bonus.v_x;
		cubgame->bonus.r_y = cubgame->bonus.v_y;
	}
	cubgame->bonus.h_line = cubgame->height;
}

void	horiontal_norm_1(t_cubd *cubgame)
{
	int		x;
	int		y;
	char	s;

	while (cubgame->bonus.h_line < cubgame->height)
	{
		x = (int)cubgame->bonus.r_x >> 6;
		y = (int)cubgame->bonus.r_y >> 6;
		s_read(x, y, cubgame, &s);
		if (s == '1' || s == 'D')
			horizontal_have_dor(cubgame, s);
		else
		{
			cubgame->bonus.r_x += cubgame->bonus.x_o;
			cubgame->bonus.r_y += cubgame->bonus.y_o;
			cubgame->bonus.h_line++;
		}
	}
}

int	t_r_g(int t1, int t2, int t3, int t4)
{
	return (t1 << 24 | t2 << 16 | t3 << 8 | t4);
}

void	pixel_set(t_cubd *cubgame, int i, int flag)
{
	int		x;
	char	*ds_t;

	ds_t = cubgame->ad[1] + ((i * cubgame->line_length[1]) + cubgame->all_i * (cubgame->bits_per_pixel[1] / 8));
	if (flag == 0)
	{
		x = t_r_g(0, cubgame->c[0], cubgame->c[1], cubgame->c[2]);
	}
	else
		x = t_r_g(0, cubgame->f[0], cubgame->f[1], cubgame->f[2]);
	*(unsigned int *)ds_t = x;
}

void	pixel_set_11(t_cubd *cubgame, int i, int c)
{
	char	*ds_t;

	ds_t = cubgame->ad[1] + ((i * cubgame->line_length[1]) 
		+ cubgame->all_i * (cubgame->bits_per_pixel[1] / 8));
	*(unsigned int *)ds_t = c;
}

void	textur_set(t_cubd *cubgame, int i, int k)
{
	char	*ds_t;
	int		x;
	int		j;

	if (cubgame->line_len == 0)
		return ;
	x = cubgame->bonus.r_a_y;
	k += cubgame->step_flag;
	j = (k << 6) / cubgame->line_len;
	ds_t = cubgame->ad[cubgame->bonus.z] + ((j * cubgame->line_length[cubgame->bonus.z]))
		+ cubgame->all_i * (cubgame->bits_per_pixel[cubgame->bonus.z] / 8);
	pixel_set_11(cubgame, i, *(unsigned int *)ds_t);
}

void	line_on_map_draw1(t_cubd *cubgame, int h, int f)
{
	int	k;
	int	i;

	k = -1;
	i = 0;
	while (i < cubgame->h_screen)
	{
		if (i < f)
			pixel_set(cubgame, i, 0);
		else if (i > h + f)
			pixel_set(cubgame, i, 1);
		else
			textur_set(cubgame, i, k++);
		i++;
	}
}

void	line_on_map_draw(t_cubd *cubgame)
{
	int	h;
	int	f;

	h = (cubgame->h_screen << 5) / cubgame->dis_t;
	cubgame->step_flag = 0;
	cubgame->line_len = h;
	if (h > cubgame->h_screen)
	{
		cubgame->step_flag = ((h - cubgame->h_screen) >> 1);
		h = cubgame->h_screen;
	}
	f = (cubgame->h_screen - h) >> 1;
	line_on_map_draw1(cubgame, h, f);
}

void	horizontal(t_cubd *cubgame)
{
	cubgame->bonus.atan_ra = 1.0 / tan(radian(cubgame->bonus.routa));
	cubgame->bonus.h_line = 0;
	if (sin(radian(cubgame->bonus.routa)) > 0.0001)
		horizon_pozition_y_plus(cubgame);
	else if (sin(radian(cubgame->bonus.routa)) < -0.0001)
		horizon_pozition_y_minus(cubgame);
	else if (sin(radian(cubgame->bonus.routa)) < 0.0001 && sin(radian(cubgame->bonus.routa)) > -0.0001)
		horizon_pozition_y_nol(cubgame);

	horiontal_norm_1(cubgame);
	cubgame->dis_t *= cos(radian(angl(cubgame->pozition - cubgame->bonus.routa)));
	if (cubgame->bonus.z_h > 3 && cubgame->bonus.z_h != 6)
		cubgame->bonus.r_a_y = (int)(cubgame->bonus.v_y) % 64;
	else
		cubgame->bonus.r_a_y = (int)(cubgame->bonus.v_x) % 64;
	line_on_map_draw(cubgame);
}

void	pixel_set_unset_s_h1(t_cubd *cubgame, int i, int j, int c)
{
	char	*dst;

	dst = cubgame->ad[1] + ((j * cubgame->line_length[0])
			+ i * (cubgame->bits_per_pixel[0] / 8));
	*(unsigned int *)dst = c;
}

void	minimap_renders(t_cubd *cubgame, int x, int y, int k)
{
	int	j;
	int	i;

	i = 0;
	while (i <= cubgame->w_screen / 50)
	{
		j = 0;
		while (j <= cubgame->h_screen / 50)
		{
			if (i == 0 || j == 0)
				pixel_set_unset_s_h1(cubgame, i + x * cubgame->w_screen / 50,
					j + y * cubgame->h_screen / 50, 0x0FF000000);
			else
				pixel_set_unset_s_h1(cubgame, i + x * cubgame->w_screen / 50,
					j + y * cubgame->h_screen / 50, k);
			j++;
		}
		i++;
	}
}


void	horizontal_rending(t_cubd *cubgame, int x, int y, int clr)
{
	char	*dst;

	dst = cubgame->ad[1] + ((y * cubgame->line_length[0])
			+ x * (cubgame->bits_per_pixel[0] / 8));
	*(unsigned int *)dst = clr;
}


void	to_player_start_init_fo_norm(t_cubd *cubgame, double x, double y)
{
	double	j;
	double	i;

	i = 0.5 - cubgame->w_screen / 250;
	while (i <= cubgame->w_screen / 250)
	{
		j = 0.5 - cubgame->h_screen / 250;
		while (j <= cubgame->w_screen / 250)
		{
			horizontal_rending(cubgame, i + x * cubgame->w_screen / 50,
				j + y * cubgame->h_screen / 50, 0xff110211);
			j++;
		}
		i++;
	}
}


void	to_player_start_init(t_cubd *cubgame)
{
	double	x;
	double	y;

	if (cubgame->px < 5)
		x = cubgame->px;
	else if (cubgame->width - cubgame->px < 5)
		x = 10 - (cubgame->width - cubgame->px);
	else
		x = 4 + (cubgame->px - (int)cubgame->px);
	if (cubgame->py < 5)
		y = cubgame->py;
	else if (cubgame->height - cubgame->py < 5)
		y = 10 - (cubgame->height - cubgame->py);
	else
		y = 5 + (cubgame->py - (int)cubgame->py);
	to_player_start_init_fo_norm(cubgame, x, y);
}


void	minimap(t_list *m, t_cubd *cubgame, double x)
{
	int		i;
	int		j;
	char	*line;

	j = 0;
	while (m && j < 10)
	{
		line = m->content;
		i = 0;
		while (line[(int)x + i] && i < 10)
		{
			if (line[(int)x + i] == '1')
				minimap_renders(cubgame, i, j, 0x2202f2);
			else if (line[(int)x + i] == 'D')
				minimap_renders(cubgame, i, j, 0x038a30);
			else
				minimap_renders(cubgame, i, j, 0x00000000);
			i++;
		}
		j++;
		m = m->next;
	}
	to_player_start_init(cubgame);
}

void	rener_mip(t_list *m, t_cubd *cubgame)
{
	double	y;
	double	x;

	if (cubgame->minimap)
		mlx_destroy_image(cubgame->init_mlx, cubgame->minimap);
	cubgame->minimap = mlx_new_image(cubgame->init_mlx, cubgame->w_screen / 5, cubgame->h_screen / 5);
	cubgame->ad[1] = mlx_get_data_addr(cubgame->minimap, &cubgame->bits_per_pixel[0],
			&cubgame->line_length[0], &cubgame->endian[0]);
	y = 0;
	while (cubgame->height > 11 && cubgame->py > y + 6 && cubgame->height > y + 10)
	{
		m = m->next;
		y++;
	}
	if (cubgame->width < 11 || cubgame->px <= 4)
		x = 0;
	else if (cubgame->width - cubgame->px <= 6)
		x = cubgame->width - 10;
	else
		x = cubgame->px - 4;
	minimap(m, cubgame, x);
	mlx_put_image_to_window(cubgame->init_mlx, cubgame->window, cubgame->minimap, 0, 0);
}

void	asd_asd_ke_r(t_cubd *cubgame)
{
	cubgame->pozition -= 5;
	cubgame->pozition = angl(cubgame->pozition);
	cubgame->dx = cos(radian(cubgame->pozition));
	cubgame->dy = -1 * sin(radian(cubgame->pozition));
}

void	symbol_tts(int i, int j, t_cubd *cubgame, char c)
{
	char	*str;
	t_list	*m;

	if (i < 0 || j < 0)
		return ;
	m = cubgame->grafic;
	while (j > 0)
	{
		j--;
		m = m->next;
	}
	str = m->content;
	str[i] = c;
}


void	asd_asd_ke_l(t_cubd *cubgame)
{
	cubgame->pozition += 5;
	cubgame->pozition = angl(cubgame->pozition);
	cubgame->dx = cos(radian(cubgame->pozition));
	cubgame->dy = -1 * sin(radian(cubgame->pozition));
}

void	render_for_map_e_s(t_cubd *cubgame)
{
	int	x;

	x = cubgame->bonus.mouse_x;
	if (cubgame->bonus.mouse_x > x)
		asd_asd_ke_r(cubgame);
	else if (cubgame->bonus.mouse_x < x)
		asd_asd_ke_l(cubgame);
	if (cubgame->flag_dor_open == '1' && cubgame->steps > 20
		&& ((int)cubgame->px != cubgame->dor_i || (int)cubgame->py != cubgame->dor_j))
		symbol_tts(cubgame->dor_i, cubgame->dor_j, cubgame, 'D');
}


void	vertical_and_horizontal_check(t_cubd *cubgame)
{
	game_drow1_sprite(cubgame);
	vertical(cubgame);		//?????????????????????????




	mlx_put_image_to_window(cubgame->init_mlx, cubgame->window, cubgame->create_fon, 0, 0);//mini map put ekran
	rener_mip(cubgame->grafic,cubgame);    //mini map
	render_for_map_e_s(cubgame);
}

int	game_drow(t_cubd *cubgame)
{
	cubgame->timer++;
	if (cubgame->timer % 20)
	{
		if (cubgame->sprite == '1')
			cubgame->sprite = '2';
		else
			cubgame->sprite = '1';
	}
	if (cubgame->timer > 200)
		cubgame->timer = 0;
	if (cubgame->create_fon)
		mlx_destroy_image(cubgame->init_mlx, cubgame->create_fon);
	cubgame->create_fon = mlx_new_image(cubgame->init_mlx, cubgame->w_screen, cubgame->h_screen);
	if (!cubgame->create_fon)
		exit_and_distroy1(cubgame, "ERROR: mlx1\n");
	cubgame->ad[1] = mlx_get_data_addr(cubgame->create_fon, &cubgame->bits_per_pixel[1],
		&cubgame->line_length[1], &cubgame->endian[1]);
	if (!cubgame->ad[1])
		exit_and_distroy1(cubgame, "ERROR: mlx2\n");


	vertical_and_horizontal_check(cubgame);
	return (0);
}