/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 14:51:19 by akurilen          #+#    #+#             */
/*   Updated: 2018/03/01 14:51:21 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fdf.h"

void	draw(t_mlx *mlx, t_v p1, t_v p2)
{
	t_line	line;

	p1.x = (int)p1.x;
	p2.x = (int)p2.x;
	p1.y = (int)p1.y;
	p2.y = (int)p2.y;
	line.start = p1;
	line.end = p2;
	if (!lineclip(&p1, &p2))
		return ;
	line.dx = (int)ft_minus_plus((int)p2.x - (int)p1.x);
	line.sx = dop(p1.x, p2.x);
	line.dy = (int)ft_minus_plus((int)p2.y - (int)p1.y);
	if ((int)p1.y < (int)p2.y)
		line.sy = 1;
	else
		line.sy = -1;
	if (line.dx > line.dy)
		line.err = line.dx / 2;
	else
		line.err = -line.dy / 2;
	while (((int)p1.x != (int)p2.x || (int)p1.y != (int)p2.y))
		if (line_process_point(mlx, &line, &p1, &p2) == 1)
			break ;
}

double	ft_ilerp(double val, double first, double second)
{
	double	fir;
	double	sec;
	double	noun;

	fir = 0.0;
	sec = 1.0;
	noun = (val - first) / (second - first);
	if (val == first)
		return (fir);
	if (val == second)
		return (sec);
	return (noun);
}

int		line_process_point(t_mlx *mlx, t_line *l, t_v *p1, t_v *p2)
{
	double	percent;
	int		for_clerp;

	if (p1->x < 0 || p1->x >= WWIDTH || p1->y < 0 || p1->y >= WHEIGHT
		|| p2->x < 0 || p2->x >= WWIDTH || p2->y < 0 || p2->y >= WHEIGHT)
		return (1);
	if (l->dx > l->dy)
		percent = ft_ilerp((int)p1->x, (int)l->start.x, (int)l->end.x);
	else
		percent = ft_ilerp((int)p1->y, (int)l->start.y, (int)l->end.y);
	for_clerp = clerp(p1->color, p2->color, percent);
	image_set_pixel(mlx, (int)p1->x, (int)p1->y, for_clerp);
	l->err2 = l->err;
	if (l->err2 > -l->dx)
	{
		l->err -= l->dy;
		p1->x += l->sx;
	}
	if (l->err2 < l->dy)
	{
		l->err += l->dx;
		p1->y += l->sy;
	}
	return (0);
}

int		dop_rout(int r1, int r2, int rout)
{
	if (r1)
		rout = r1;
	else
		rout = r2;
	return (rout);
}

int		lineclip(t_v *p1, t_v *p2)
{
	t_v		v;
	int		r1;
	int		r2;
	int		rout;

	r1 = region(p1->x, p1->y);
	r2 = region(p2->x, p2->y);
	while (!(!(r1 | r2) || (r1 & r2)))
	{
		rout = dop_rout(r1, r2, rout);
		v = clip_xy(p1, p2, rout);
		if (rout == r1)
		{
			p1->x = v.x;
			p1->y = v.y;
			r1 = region(p1->x, p1->y);
		}
		else
		{
			p2->x = v.x;
			p2->y = v.y;
			r2 = region(p2->x, p2->y);
		}
	}
	return (!(r1 | r2));
}
