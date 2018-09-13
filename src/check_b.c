/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:14:31 by akurilen          #+#    #+#             */
/*   Updated: 2018/02/26 17:14:33 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fdf.h"

char	*check_b(int j, char *buf)
{
	int		i;
	int		zap;

	i = -1;
	zap = 0;
	while (buf[++i])
	{
		if (buf[i] != ' ')
			j++;
		if (buf[i] == ' ')
			if (buf[i - 1] != ' ')
				zap++;
	}
	i = 0;
	return (check_dop(i, j, zap, buf));
}

char	*check_dop(int i, int j, int zap, char *buf)
{
	int		k;
	int		o;
	char	*line_x;

	k = -1;
	o = 0;
	line_x = ft_memalloc(sizeof(char) * (j + zap + 1));
	ft_bzero(line_x, j + zap + 1);
	if (buf[i] == ' ')
		while (buf[i] == ' ')
			i++;
	while (buf[i] != '\0' && o < j && buf[i])
	{
		if (buf[i] != ' ' && buf[i] != '\0')
		{
			line_x[++k] = buf[i];
			o++;
		}
		else if (buf[i] != '\0' && buf[i] == ' ')
			if (buf[i - 1] != ' ')
				line_x[++k] = ',';
		i++;
	}
	return (line_x);
}

int		dop(double x1, double x2)
{
	int sx;

	if (x1 < x2)
		sx = 1;
	else
		sx = -1;
	return (sx);
}

t_mlx	*read_f(char *title, t_mlx *mlx, t_str *lin)
{
	int width;
	int height;

	width = f_width(lin);
	height = f_height(lin) + 1;
	if (!(mlx = ft_memalloc(sizeof(t_mlx))))
		return (NULL);
	if ((mlx->for_ = mlx_init()) == NULL)
		return (mlxdel(mlx));
	if ((mlx->wi = mlx_new_window(mlx->for_, WWIDTH, WHEIGHT, title)) == NULL ||
		(mlx->matrix = ft_memalloc(sizeof(t_matrix *))) == NULL ||
		(mlx->mouse = ft_memalloc(sizeof(t_mouse))) == NULL ||
		(mlx->picture = new_picture(mlx)) == NULL)
		return (mlxdel(mlx));
	mlx->matrix->step_y = 0.5;
	mlx->matrix->step_x = 0.5;
	mlx->matrix->c_x = WWIDTH / 2;
	mlx->matrix->c_y = WHEIGHT / 2;
	if (!(mlx->win = get_win(width, height, mlx->win)))
		return (mlx = mlxdel(mlx));
	if (!(mlx = build_window_z(width, height, lin, mlx)))
		return (NULL);
	if (lin != NULL)
		ft_tstrdel(&lin);
	return (mlx);
}

t_win	*prod(t_win *map, int col_x)
{
	int i;
	int j;

	i = -1;
	while (++i < map->col_y)
	{
		j = -1;
		while (++j < map->col_x && map[i].line_x[j])
		{
			if (map->v[i * col_x + j] != NULL)
				free(map->v[i * col_x + j]);
			map->v[i * col_x + j] = get_vector(j, i, map[i].line_x[j]);
		}
	}
	return (map);
}
