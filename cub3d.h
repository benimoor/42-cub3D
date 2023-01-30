#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include "./libft/libft.h"
# include <mlx.h>
# include <fcntl.h>

typedef struct s_bonus
{
	double	i;
	double	j;
	double	k;
	double	x_x;
	double	y_y;
	double	scale;
	double	t_x;
	double	t_x_step;
	double	t_y_step;
	double	routa;
	double	px;
	double	py;
	double	tan_ra;
	int		h_line;
	int		z;
	double	r_x;
	double	r_y;
	double	mouse_x;
	double	mouse_y;
	double	x_o;
	double	y_o;
	double	v_x;
	double	v_y;
	int		z_h;
	double	atan_ra;
	double	pozition_r;
	int		r_a_y;
}	t_bonus;

typedef	struct	cub3d
{
	int			flag;
	int			i;
	int			flag_one;
	int			have_zerro;
	double		pozition;
	double		player_h;
	double		x;
	double		y;
	double		w;
	double		s;
	double		px;
	double		py;
	double		dx;
	double		dy;
	double		b;
	double		width;
	double		height;
	double		dis_t;
	double		spr_scale;
	double		t_y;
	double		t_x;
	void		*create_fon;
	void		*dur;
	void		*key1;
	void		*key2;

	void		*so;
	void		*ea;
	void		*we;
	void		*no;
	void		*init_mlx;
	void		*window;
	int			c[3];
	int			f[3];
	int			bits_per_pixel[9];
	char		symbol;
	char		game_player;
	char		sprite;
	char		*ad[9];
	int			line_length[9];
	int			endian[9];
	double		keypy;
	double		a_l;
	int			ds;
	double		keypx;
	char		*line;
	int			x_1;
	int			timer;
	int			steps;
	int			dor_i;
	int			dor_j;
	int			flag_dor_open;
	double		slayd_x;
	double		slayd_y;
	double		step_flag;
	int			line_len;
	int			all_i;
	int			h_screen;
	int			w_screen;
	void		*minimap;
	t_bonus		bonus;
	t_list		*grafic;
}				t_cubd;

void	my_print(char *str);
int		check_map(char *av, t_cubd *cubgame);
void	exit_game(t_cubd	*cubgame, char *str);
void	func_null(t_cubd *cubgame);
void	free_all(t_cubd *cubgame);
void	floor_or_ceiling(t_cubd	*cubgame, char  *str, char c);
void	ft_texture(t_cubd	*cubgame, char  *str, char c);
void    map_one(t_cubd *cubgame, int fd);
char	*gnl(int fd);
void	check_zero_around(t_cubd *cubgame, char	*str1, char *str2, char *str3);
void	start_draw_game(t_cubd	*cubgame);
void	width_and_height_check(t_cubd *cubgame);
void	player_focused(t_cubd *cubgame);
double	radian(double degry);
int		exit_and_distroy(t_cubd	*cubgame);
int		key(t_cubd	*cubgame, int keyx);
int		game_drow(t_cubd *cubgame);
void	exit_and_distroy1(t_cubd	*cubgame, char *str);
void	s_read(int i, int j, t_cubd *cubgame, char *s);
void	horizontal(t_cubd *cubgame);

#endif