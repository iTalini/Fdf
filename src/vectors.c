/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 12:47:51 by akurilen          #+#    #+#             */
/*   Updated: 2018/03/07 12:47:54 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fdf.h"

t_v		c_v(t_v vector, t_mlx *mlx)
{
	vector.x -= cord(mlx, 'x');
	vector.y -= cord(mlx, 'y');
	vector.z -= cord(mlx, 'z');
	vector = pov(mlx, vector);
	vector.x *= mlx->matrix->scale;
	vector.y *= mlx->matrix->scale;
	vector.x += mlx->matrix->c_x;
	vector.y += mlx->matrix->c_y;
	return (vector);
}

double	cord(t_mlx *mlx, char a)
{
	double ans;

	if (a == 'x')
		ans = (double)(mlx->win->col_x - 1) / 2.0f;
	if (a == 'y')
		ans = (double)(mlx->win->col_y - 1) / 2.0f;
	if (a == 'z')
		ans = (double)(mlx->win->min + mlx->win->max) / 2.0f;
	return (ans);
}

t_v		many(t_v **v, int width, int height, int col_x)
{
	return (*v[height * col_x + width]);
}

void	change_vector(t_mlx *mlx)
{
	t_v		vec;
	int		h_y;
	int		w_x;
	int		x;

	x = mlx->win->col_x;
	ft_bzero(mlx->picture->ptr, WWIDTH * WHEIGHT * mlx->picture->w);
	w_x = 0;
	while (w_x < x)
	{
		h_y = 0;
		while (h_y < mlx->win->col_y)
		{
			vec = c_v(many(mlx->win->v, w_x, h_y, x), mlx);
			if (w_x + 1 < mlx->win->col_x)
				draw(mlx, vec, c_v(many(mlx->win->v, w_x + 1, h_y, x), mlx));
			if (h_y + 1 < mlx->win->col_y)
				draw(mlx, vec, c_v(many(mlx->win->v, w_x, h_y + 1, x), mlx));
			h_y++;
		}
		w_x++;
	}
	mlx_put_image_to_window(mlx->for_, mlx->wi, mlx->picture->pixel, 0, 0);
}
