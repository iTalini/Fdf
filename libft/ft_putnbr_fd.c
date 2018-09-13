/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 22:13:01 by dkalashn          #+#    #+#             */
/*   Updated: 2017/11/23 16:17:47 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		add_fd(char *res, int i, int n, int fd)
{
	int sign;

	sign = 1;
	res[i] = '\0';
	if (n < 0)
	{
		ft_putchar_fd(45, fd);
		sign = -1;
	}
	while (i)
	{
		res[i - 1] = sign * (n % 10) + 48;
		i--;
		n = n / 10;
	}
	while (res[i])
	{
		ft_putchar_fd(res[i], fd);
		i++;
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	int		n_p;
	int		i;
	int		j;
	char	res[12];

	i = 1;
	j = 0;
	n_p = n;
	while (n_p / 10 != 0)
	{
		i++;
		n_p = n_p / 10;
	}
	add_fd(res, i, n, fd);
}
