/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 19:37:23 by akurilen          #+#    #+#             */
/*   Updated: 2018/02/07 19:37:25 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fdf.h"

t_mlx	*build_window_z(int x, int y, t_str *lin, t_mlx *mlx)
{
	int		i;

	i = -1;
	while (++i <= y - 1 && lin)
	{
		mlx->win[i].line_x = ft_strsplit(lin->content, ',');
		lin = lin->next;
	}
	if (mlx->win->v != NULL)
		free(mlx->win->v);
	if (!(mlx->win->v = ft_memalloc(sizeof(t_v) * y * x)))
		return (mlx = mlxdel(mlx));
	i = -1;
	while (++i < y * x)
		if (!(mlx->win->v[i] = ft_memalloc(sizeof(t_v) * y * x)))
			return (mlx = mlxdel(mlx));
	mlx->win = prod(mlx->win, x);
	mlx->matrix->scale = iff(x, y);
	if (lin != NULL)
		ft_tstrdel(&lin);
	return (for_build(mlx));
}

int		ft_close(char *why)
{
	ft_putendl(why);
	if (why)
		ft_strdel(&why);
	return (1);
}

int		size_line(char *o)
{
	int x;
	int ans;

	x = 0;
	ans = -1;
	while (o[++ans])
		if (o[ans] != ',')
			x++;
	return (ans - x + 1);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_str	*lin;

	mlx = NULL;
	lin = NULL;
	if ((lin = gnline(argv[1], lin)) == NULL)
		return (ft_close("error: invalid file"));
	if (argc < 2)
		return (ft_close("error: not enought argumets."));
	if ((mlx = read_f(argv[1], mlx, lin)) == NULL)
		return (ft_close("error: some memory problems."));
	mlx_key_hook(mlx->wi, hook_keydown, mlx);
	mlx_hook(mlx->wi, 4, 0, hook_mousedown, mlx);
	mlx_hook(mlx->wi, 5, 0, hook_mouseup, mlx);
	mlx_hook(mlx->wi, 6, 0, hook_mousemove, mlx);
	mlx_loop(mlx->for_);
	return (0);
}
