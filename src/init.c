/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 12:03:46 by akurilen          #+#    #+#             */
/*   Updated: 2018/03/06 12:03:48 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fdf.h"

void		image_set_pixel(t_mlx *mlx, int x, int y, int c)
{
	if (x < 0 || x >= WWIDTH || y < 0 || y >= WHEIGHT)
		return ;
	*(int *)(mlx->picture->ptr + ((x + y * WWIDTH) * mlx->picture->w)) = c;
}

t_mlx		*mlxdel(t_mlx *mlx)
{
	if (mlx == NULL)
		return (NULL);
	if (mlx->wi != NULL && mlx->for_ != NULL)
		mlx_destroy_window(mlx->for_, mlx->wi);
	if (mlx->matrix != NULL)
		ft_memdel((void **)&mlx->matrix);
	if (mlx->mouse != NULL)
		ft_memdel((void **)&mlx->mouse);
	if (mlx->picture != NULL)
		del_picture(mlx, mlx->picture);
	if (mlx->win != NULL)
		windel(mlx->win);
	if (mlx != NULL)
		ft_memdel((void **)&mlx);
	mlx = NULL;
	return (NULL);
}

t_picture	*del_picture(t_mlx *mlx, t_picture *pic)
{
	if (pic != NULL)
	{
		if (pic->pixel != NULL)
			mlx_destroy_image(mlx->for_, pic->pixel);
		ft_memdel((void **)&pic);
	}
	return (NULL);
}

t_picture	*new_picture(t_mlx *mlx)
{
	t_picture		*pic;

	if ((pic = ft_memalloc(sizeof(t_picture))) == NULL)
		return (NULL);
	if ((pic->pixel = mlx_new_image(mlx->for_, WWIDTH, WHEIGHT)) == NULL)
		return (del_picture(mlx, pic));
	pic->ptr = mlx_get_data_addr(pic->pixel, &pic->w, &pic->stride, &pic->end);
	pic->w /= 8;
	return (pic);
}
