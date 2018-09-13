/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 12:52:55 by akurilen          #+#    #+#             */
/*   Updated: 2018/03/22 12:52:58 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fdf.h"

void	find_depth(t_win *m)
{
	int		min;
	int		max;
	t_v		v;
	t_v		cur;

	min = 2147483647;
	max = -2147483648;
	v.y = 0;
	while (v.y < m->col_y)
	{
		v.x = 0;
		while (v.x < m->col_x)
		{
			cur = *m->v[(int)v.y * m->col_x + (int)v.x];
			if (cur.z < min)
				min = cur.z;
			if (cur.z > max)
				max = cur.z;
			v.x++;
		}
		v.y++;
	}
	m->min = min;
	m->max = max;
}

void	fill_colors(t_win *m)
{
	t_v		v;
	t_v		*cur;
	double	for_clerp;

	v.y = 0;
	while (v.y < m->col_y)
	{
		v.x = 0;
		while (v.x < m->col_x)
		{
			cur = m->v[(int)v.y * m->col_x + (int)v.x];
			for_clerp = ft_ilerp(cur->z, m->min, m->max);
			cur->color = clerp(0xFF0000, 0xFFFFFF, for_clerp);
			v.x++;
		}
		v.y++;
	}
}

t_win	*get_win(int width, int height, t_win *win)
{
	int i;

	i = -1;
	win = ft_memalloc(sizeof(t_win) * height);
	while (++i < height)
	{
		win[i].col_x = width;
		win[i].col_y = height;
		win[i].min = 0;
		win[i].max = 0;
		if ((win[i].v = ft_memalloc(sizeof(t_v *) * width * height)) == NULL)
		{
			windel(win);
			return (NULL);
		}
	}
	return (win);
}

void	func(t_str **lin, t_str **new)
{
	t_str	*head;

	head = NULL;
	if (!*lin)
		*lin = *new;
	else
	{
		head = *lin;
		while ((*lin)->next)
			*lin = (*lin)->next;
		(*lin)->next = *new;
		*lin = (*lin)->next;
		(*lin)->next = NULL;
		*lin = head;
	}
}
