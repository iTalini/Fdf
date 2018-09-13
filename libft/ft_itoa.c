/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:31:28 by dkalashn          #+#    #+#             */
/*   Updated: 2017/11/23 16:18:34 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*pos(int count, int n, char *res)
{
	res = (char *)malloc(count + 1);
	if (!res)
		return (NULL);
	res[count] = '\0';
	while (count)
	{
		res[count - 1] = (n % 10) + 48;
		n = n / (10);
		count--;
	}
	return (res);
}

static char		*neg(int count, int n, char *res)
{
	res = (char *)malloc(count + 2);
	if (!res)
		return (NULL);
	res[0] = '-';
	res[count + 1] = '\0';
	while (count + 1)
	{
		res[count] = (-1) * (n % 10) + 48;
		n = n / (10);
		count--;
	}
	res[0] = '-';
	return (res);
}

char			*ft_itoa(int n)
{
	int		i;
	int		count;
	char	*res;
	int		nbr;

	res = NULL;
	count = 1;
	i = 0;
	nbr = n;
	while (nbr / (10) != 0)
	{
		count++;
		nbr = nbr / (10);
	}
	if (nbr < 0)
		res = neg(count, n, res);
	else
		res = pos(count, n, res);
	return (res);
}
