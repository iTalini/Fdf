/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_w_gnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 19:40:11 by akurilen          #+#    #+#             */
/*   Updated: 2018/06/23 19:40:14 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fdf.h"

t_str	*gnline(char *title, t_str *lin)
{
	int		fd;
	char	*line;
	t_str	*new;

	if ((fd = open(title, O_RDONLY)) == -1)
		return (NULL);
	if (!(fd = open(title, O_RDONLY)))
		return (NULL);
	line = NULL;
	new = NULL;
	while ((get_next_line(fd, &line)) > 0)
	{
		if (new == NULL)
			new = ft_memalloc(sizeof(t_str *));
		ft_bzero(new, sizeof(t_str *));
		new->content = check_b(0, line);
		new->next = NULL;
		func(&lin, &new);
		new = new->next;
		free(line);
	}
	if (new != NULL)
		ft_tstrdel(&new);
	return (lin);
}

void	ft_tstrdel(t_str **alst)
{
	t_str *tmp;
	t_str *current;

	if (!alst)
		return ;
	tmp = *alst;
	current = tmp;
	while (current)
	{
		tmp = current->next;
		ft_strdel(&current->content);
		free(current);
		current = tmp;
	}
	ft_memdel((void **)current);
	ft_memdel((void **)tmp);
	*alst = NULL;
}

int		f_width(t_str *lin)
{
	int width;

	width = 0;
	while (lin)
	{
		if (width == 0)
			width = size_line(lin->content);
		if (width != size_line(lin->content))
		{
			ft_tstrdel(&lin);
			return (0);
		}
		lin = lin->next;
	}
	ft_tstrdel(&lin);
	return (width);
}

int		f_height(t_str *lin)
{
	int height;

	height = -1;
	while (lin)
	{
		height++;
		lin = lin->next;
	}
	ft_tstrdel(&lin);
	return (height);
}
