/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:59:05 by dkalashn          #+#    #+#             */
/*   Updated: 2017/11/22 20:07:56 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	char			*dest1;
	char const		*src1;

	i = 0;
	dest1 = dest;
	src1 = src;
	while (i < n)
	{
		if ((unsigned char)src1[i] == (unsigned char)c)
		{
			dest1[i] = (unsigned char)src1[i];
			return (&dest1[i + 1]);
		}
		dest1[i] = (unsigned char)src1[i];
		i++;
	}
	return (NULL);
}
