/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 11:51:21 by akurilen          #+#    #+#             */
/*   Updated: 2018/02/10 11:51:23 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include <mlx.h>
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>

# define MAX_FD 1000
# define WHEIGHT 1000
# define WWIDTH 1280

typedef struct		s_matrix
{
	double			c_x;
	double			c_y;
	double			step_x;
	double			step_y;
	double			scale;
}					t_matrix;

typedef struct		s_v
{
	double			x;
	double			y;
	double			z;
	int				color;
}					t_v;

typedef struct		s_line
{
	t_v				start;
	t_v				end;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				err2;
}					t_line;

typedef struct		s_mouse
{
	char			newline;
	int				x1;
	int				y1;
	int				x2;
	int				y2;
}					t_mouse;

typedef struct		s_picture
{
	void			*pixel;
	char			*ptr;
	int				w;
	int				stride;
	int				end;
}					t_picture;

typedef struct		s_win
{
	char			*buf;
	char			**line_x;
	int				col_x;
	int				col_y;
	int				min_x;
	int				min_y;
	int				min;
	int				max;
	t_v				**v;
}					t_win;

typedef struct		s_mlx
{
	void			*wi;
	void			*for_;
	t_picture		*picture;
	t_matrix		*matrix;
	t_mouse			*mouse;
	t_win			*win;
}					t_mlx;

typedef struct		s_str
{
	char			*content;
	struct s_str	*next;
}					t_str;

t_mlx				*init(char *title);
void				ft_tstrdel(t_str **alst);
int					ft_close(char *why);
t_str				*gnline(char *title, t_str *lin);
int					f_width(t_str *lin);
int					f_height(t_str *lin);
void				func(t_str **lin, t_str **new);
int					iff(int col_x, int col_y);
char				*check_b(int j, char *buf);
t_mlx				*for_build(t_mlx *mlx);
t_v					*get_vector(int x, int y, char *str);
int					how_m(char *str, int what);
t_mlx				*build_window_z(int x, int y, t_str	*lin, t_mlx *mlx);
void				image_set_pixel(t_mlx *mlx, int x, int y, int col);
void				delet_picture(t_picture *picture);
t_mlx				*mlxdel(t_mlx *mlx);
t_picture			*del_picture(t_mlx *mlx, t_picture *pic);
t_picture			*new_picture(t_mlx *mlx);
t_v					many(t_v **v, int width, int height, int col_x);
void				windel(t_win *win);
int					hook_keydown(int key, t_mlx *mlx);
t_v					pov(t_mlx *mlx, t_v p);
void				change_vector(t_mlx *mlx);
t_v					c_v(t_v vector, t_mlx *mlx);
double				ft_ilerp(double val, double first, double second);
int					line_process_point(t_mlx *mlx, t_line *l, t_v *p1, t_v *p2);
int					lineclip(t_v *p1, t_v *p2);
int					dop_rout(int r1, int r2, int rout);
int					region(int x, int y);
t_v					clip_xy(t_v *p1, t_v *p2, int rout);
int					clerp(int c1, int c2, double p);
int					hook_mousedown(int button, int x, int y, t_mlx *mlx);
int					hook_mouseup(int button, int x, int y, t_mlx *mlx);
int					hook_mousemove(int x, int y, t_mlx *mlx);
int					size_line(char *o);
void				find_depth(t_win *m);
void				fill_colors(t_win *m);
void				cleanup(t_win *map);
t_win				*get_win(int width, int height, t_win *win);
void				draw(t_mlx *mlx, t_v p1, t_v p2);
double				cord(t_mlx *mlx, char a);
int					dop(double x1, double x2);
char				*check_dop(int i, int j, int zap, char *buf);
t_mlx				*read_f(char *title, t_mlx *mlx, t_str *lin);
t_win				*prod(t_win *map, int col_x);
char				**strfdf(t_str **new, char c);
#endif
