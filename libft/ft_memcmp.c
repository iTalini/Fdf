/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:51:01 by dkalashn          #+#    #+#             */
/*   Updated: 2017/11/22 20:12:02 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t					i;
	int						res;
	unsigned const char		*s_1;
	unsigned const char		*s_2;

	s_1 = s1;
	s_2 = s2;
	i = 0;
	res = 0;
	while (i < n)
	{
		if (s_1[i] != s_2[i])
		{
			res = (s_1[i] - s_2[i]);
			return (res);
		}
		i++;
	}
	return (res);
}
