/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 17:11:06 by akurilen          #+#    #+#             */
/*   Updated: 2018/04/12 17:11:08 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fdf.h"

t_mlx	*for_build(t_mlx *mlx)
{
	mlx->win->min_x = 0;
	mlx->win->min_y = 0;
	find_depth(mlx->win);
	fill_colors(mlx->win);
	change_vector(mlx);
	return (mlx);
}

void	windel(t_win *win)
{
	int i;

	i = -1;
	if (!win)
		return ;
	if ((void *)win->buf != NULL)
		ft_strdel(&win->buf);
	if ((void **)win->v != NULL)
		ft_memdel((void **)win->v);
	if ((void *)win->line_x != NULL)
	{
		while (win->line_x[++i])
			ft_memdel((void **)&win->line_x[i]);
		ft_memdel((void **)&win->line_x);
	}
	ft_memdel((void **)&win);
}
