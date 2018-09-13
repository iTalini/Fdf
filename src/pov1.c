/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prob_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:32:17 by akurilen          #+#    #+#             */
/*   Updated: 2018/02/13 13:32:23 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fdf.h"

t_v		pov(t_mlx *mlx, t_v p)
{
	t_v		v;
	double	dop_x;
	double	dop_y;
	double	dop_z;

	dop_x = p.x;
	dop_z = p.z;
	v.x = cos(mlx->matrix->step_y) * dop_x + sin(mlx->matrix->step_y) * dop_z;
	v.z = -sin(mlx->matrix->step_y) * dop_x + cos(mlx->matrix->step_y) * dop_z;
	dop_y = p.y;
	dop_z = v.z;
	v.y = cos(mlx->matrix->step_x) * dop_y - sin(mlx->matrix->step_x) * dop_z;
	v.z = sin(mlx->matrix->step_x) * dop_y + cos(mlx->matrix->step_x) * dop_z;
	v.color = p.color;
	return (v);
}

int		iff(int col_x, int col_y)
{
	if (col_x >= 400 || col_y >= 400)
		return (2);
	if (col_x >= 300 || col_y >= 300)
		return (6);
	if (col_x >= 200 || col_y >= 200)
		return (10);
	if (col_x >= 100 || col_y >= 100)
		return (15);
	if (col_x >= 50 || col_y >= 50)
		return (20);
	if (col_x >= 25 || col_y >= 25)
		return (26);
	else
		return (32);
}
