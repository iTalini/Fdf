/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_dop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 19:22:27 by akurilen          #+#    #+#             */
/*   Updated: 2018/03/14 19:22:28 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fdf.h"

int		region(int x, int y)
{
	int c;

	c = 0;
	if (y >= WHEIGHT)
		c |= 1;
	else if (y < 0)
		c |= 2;
	if (x >= WWIDTH)
		c |= 4;
	else if (x < 0)
		c |= 8;
	return (c);
}

t_v		clip_xy(t_v *p1, t_v *p2, int rout)
{
	t_v		v;

	if (rout & 1)
	{
		v.x = p1->x + (p2->x - p1->x) * (WHEIGHT - p1->y) / (p2->y - p1->y);
		v.y = WHEIGHT - 1;
	}
	else if (rout & 2)
	{
		v.x = p1->x + (p2->x - p1->x) * -p1->y / (p2->y - p1->y);
		v.y = 0;
	}
	else if (rout & 4)
	{
		v.x = WWIDTH - 1;
		v.y = p1->y + (p2->y - p1->y) * (WWIDTH - p1->x) / (p2->x - p1->x);
	}
	else
	{
		v.x = 0;
		v.y = p1->y + (p2->y - p1->y) * -p1->x / (p2->x - p1->x);
	}
	return (v);
}

int		clerp(int c1, int c2, double p)
{
	int r;
	int g;
	int b;

	if (c1 == c2)
		return (c1);
	r = ft_lerpi((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, p);
	g = ft_lerpi((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, p);
	b = ft_lerpi(c1 & 0xFF, c2 & 0xFF, p);
	return (r << 16 | g << 8 | b);
}

int		how_m(char *str, int what)
{
	int	ans;
	int i;
	int col_zap;

	i = 0;
	ans = 0;
	col_zap = 0;
	while (str[i])
	{
		if (col_zap == what)
			while (str[i] != ',' && str[i] != '\0')
			{
				i++;
				ans++;
			}
		if (col_zap != what && str[i] == ',')
			col_zap++;
		i++;
	}
	return (ans);
}

t_v		*get_vector(int x, int y, char *str)
{
	t_v		*v;

	v = ft_memalloc(sizeof(t_v));
	v->x = (double)x;
	v->y = (double)y;
	v->z = (double)ft_atoi(str);
	ft_strdel(&str);
	v->color = 0xFFFFFF;
	return (v);
}
