/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvardany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:01:17 by hvardany          #+#    #+#             */
/*   Updated: 2023/02/09 23:01:19 by hvardany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct cub3d
{
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
	char		is_key;
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
	char		sprite_st;
	int			line_len;
	int			all_i;
	int			h_screen;
	int			w_screen;
	void		*minimap;
	int			zeros;
	t_bonus		bonus;
	t_list		*grafic;
}				t_cubd;

void	my_print(char *str);
int		check_map(char *av, t_cubd *cubgame);
void	exit_game(t_cubd	*cubgame, char *str);
void	func_null(t_cubd *cubgame);
void	free_all(t_cubd *cubgame);
void	floor_or_ceiling(t_cubd	*cubgame, char *str, char c);
void	ft_texture(t_cubd	*cubgame, char *str, char c);
void	map_one(t_cubd *cubgame, int fd);
char	*gnl(int fd);
void	check_zero_around(t_cubd *cubgame, char	*str1, char *str2, char *str3);
void	start_draw_game(t_cubd	*cubgame);
void	width_and_height_check(t_cubd *cubgame);
void	player_focused(t_cubd *cubgame);
double	radian(double degry);
int		exit_and_distroy(t_cubd	*cubgame);
int		key(int keyx, t_cubd *cubgame);
int		game_drow(t_cubd *cubgame);
void	exit_and_distroy1(t_cubd	*cubgame, char *str);
void	horizontal(t_cubd *cubgame);
void	vertical_start(t_cubd *cubgame);
char	get_map_sym(int mx, int my, t_cubd *cubgame);
void	func_cos_vert_minus(t_cubd *cubgame);
void	func_cos_vert_noll(t_cubd *cubgame);
void	game_drow2_vertical(t_cubd *cubgame);
char	s_read(int i, int j, t_cubd *cubgame);
void	func_cos_vert_plus(t_cubd *cubgame);
void	horizontal(t_cubd *cubgame);
void	horiontal_norm_1(t_cubd *cubgame);
void	horizontal_have_dor(t_cubd *cubgame, char s);
void	horizon_pozition_y_nol(t_cubd *cubgame);
void	horizon_pozition_y_minus(t_cubd *cubgame);
void	horizon_pozition_y_plus(t_cubd *cubgame);
double	angl(double t);
void	line_on_map_draw(t_cubd *cubgame);
void	rener_mip(t_list *m, t_cubd *cubgame);
void	asd_asd_ke_r(t_cubd *cubgame);
void	symbol_tts(int i, int j, t_cubd *cubgame, char c);
void	asd_asd_ke_l(t_cubd *cubgame);
void	minimap(t_list *m, t_cubd *cubgame, double x);
void	pixel_set_unset_s_h1(t_cubd *cubgame, int i, int j, int c);
void	horizontal_rending(t_cubd *cubgame, int x, int y, int clr);
void	to_player_start_init_fo_norm(t_cubd *cubgame, double x, double y);
void	to_player_start_init(t_cubd *cubgame);
int		create_trgb(int t, int r, int g, int b);
void	minimap_renders(t_cubd *cubgame, int x, int y, int k);
void	my_mlx_pixel_put(t_cubd *game, int x, int y, int clr);
int		t_r_g(int t1, int t2, int t3, int t4);
void	pixel_set(t_cubd *cubgame, int i, int flag);
void	textur_set(t_cubd *cubgame, int i, int k);
void	put_texture_pixel(t_cubd *cubgame, int x, int y, int k);
void	search_null_mlx(t_cubd	*cubgame);
void	start_draw_game1(t_cubd	*cubgame);
void	dx_dy(t_cubd	*cubgame);
int		t_r_g(int t1, int t2, int t3, int t4);
void	vertical(t_cubd *cubgame);
void	sprite_drov(t_cubd *cubgame);
void	put_sprite(t_cubd *cubgame, int y);
void	vertical_s_d_r_norm(t_cubd *cubgame, char s);
void	func_null(t_cubd *cubgame);
void	func_a(t_cubd	*cubgame);
void	func_s(t_cubd	*cubgame);
void	func_d(t_cubd	*cubgame);
void	func_open_dor(t_cubd	*cubgame, int i, int j, char s);
void	func_closs_dor1(t_cubd	*cubgame, int i, int j, char s);
void	set_nol(int i, int j, t_cubd *cubgame, char c);
void	func_w(t_cubd	*cubgame);
void	func_s_read_2(int i, int j, t_cubd *cubgame, char *s);
char	s_read(int i, int j, t_cubd *cubgame);
void	set_nol(int i, int j, t_cubd *cubgame, char c);
void	check_around(t_cubd *cubgame, char	*str1, char *str2, char *str3);
int		when_have_zerro(char *str);
void	when_all_zerro(t_cubd *cubgame, char	*str1, char *str2, char *str3);
void	list_norm(t_cubd *cubgame, t_list *l, t_list *l_1, t_list *l_2);
int		player(char *str, t_cubd *cubgame);
void	time(t_cubd *cubgame);
void	maprender(t_cubd *cubgame);
int		game_drow(t_cubd *cubgame);
void	game_drow1_sprite(t_cubd *cubgame);
void	vertical_and_horizontal_check(t_cubd *cubgame);

#endif
