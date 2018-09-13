/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:26:12 by dkalashn          #+#    #+#             */
/*   Updated: 2017/11/22 20:13:21 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*res;

	res = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (res[i] == (unsigned char)c)
			return (&res[i]);
		i++;
	}
	return (0);
}
