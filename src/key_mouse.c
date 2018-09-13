/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 17:01:53 by akurilen          #+#    #+#             */
/*   Updated: 2018/03/06 17:01:54 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fdf.h"

int		hook_keydown(int key, t_mlx *mlx)
{
	(void)mlx;
	if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int		hook_mousedown(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	if (y < 0)
		return (0);
	mlx->mouse->newline |= 1 << button;
	return (0);
}

int		hook_mouseup(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	mlx->mouse->newline &= ~(1 << button);
	return (0);
}

int		hook_mousemove(int x, int y, t_mlx *mlx)
{
	mlx->mouse->x2 = mlx->mouse->x1;
	mlx->mouse->y2 = mlx->mouse->y1;
	mlx->mouse->x1 = x;
	mlx->mouse->y1 = y;
	if (mlx->mouse->newline & (1 << 1) && mlx->mouse->newline & (1 << 2))
	{
		mlx->matrix->c_x += (x - mlx->mouse->x2);
		mlx->matrix->c_y += (y - mlx->mouse->y2);
	}
	else if (mlx->mouse->newline & (1 << 1))
	{
		mlx->matrix->step_x += (mlx->mouse->y2 - y) / 200.0f;
		mlx->matrix->step_y -= (mlx->mouse->x2 - x) / 200.0f;
	}
	else if (mlx->mouse->newline & (1 << 2))
	{
		mlx->matrix->scale += (mlx->mouse->y2 - y) / 10.0f + 0.5f;
		if (mlx->matrix->scale < 1)
			mlx->matrix->scale = 1;
	}
	if (mlx->mouse->newline)
		change_vector(mlx);
	return (0);
}
