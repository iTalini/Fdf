/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 21:06:04 by dkalashn          #+#    #+#             */
/*   Updated: 2017/11/23 16:15:43 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		add(char *res, int i, int n, int sign)
{
	res[i] = '\0';
	if (n < 0)
	{
		ft_putchar(45);
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
		ft_putchar(res[i]);
		i++;
	}
}

void			ft_putnbr(int n)
{
	int		n_p;
	int		i;
	int		j;
	int		sign;
	char	res[12];

	sign = 1;
	i = 1;
	j = 0;
	n_p = n;
	while (n_p / 10 != 0)
	{
		i++;
		n_p = n_p / 10;
	}
	add(res, i, n, sign);
}
