/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:17:25 by dkalashn          #+#    #+#             */
/*   Updated: 2017/11/23 16:19:18 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		calc(const char *str)
{
	int i;
	int res;
	int sign;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}

int				ft_atoi(const char *str)
{
	int res;
	int i;

	i = 0;
	res = 0;
	if (!str || str == NULL)
		return (0);
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
				str[i] == '\f' || str[i] == '\r' || str[i] == '\v')
			i++;
		if (((str[i] == '-' || str[i] == '+') && (str[i + 1] >= '0' &&
						str[i + 1] <= '9')) || (str[i] >= '0' && str[i] <= '9'))
			res = calc(&str[i]);
		return (res);
	}
	return (res);
}
