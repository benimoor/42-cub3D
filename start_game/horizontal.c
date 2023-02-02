#include "../cub3d.h"

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
	cubgame->bonus.r_y = (((int)cubgame->bonus.py >> 6) << 6) + 64;
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
		cubgame->zeros = cubgame->bonus.z_h;
		if (s == 'D')
			cubgame->zeros = 6;
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
		s = s_read(x, y, cubgame);
		if (s == '1' || s == 'D')
			horizontal_have_dor(cubgame, s);
	// 	else
	// 	{
	// 		cubgame->bonus.r_x += cubgame->bonus.x_o;
	// 		cubgame->bonus.r_y += cubgame->bonus.y_o;
			cubgame->bonus.h_line++;
	// 	}
	}
}

void	horizontal(t_cubd *cubgame)
{
	cubgame->bonus.atan_ra = 1.0 / tan(radian(cubgame->bonus.routa));
	cubgame->bonus.h_line = 0;
	if (sin(radian(cubgame->bonus.routa)) > 0.0001)
		horizon_pozition_y_plus(cubgame);
	else if (sin(radian(cubgame->bonus.routa)) < -0.0001)
		horizon_pozition_y_minus(cubgame);
	else if (sin(radian(cubgame->bonus.routa)) < 0.0001 
			&& sin(radian(cubgame->bonus.routa)) > -0.0001)
		horizon_pozition_y_nol(cubgame);

	horiontal_norm_1(cubgame);

}