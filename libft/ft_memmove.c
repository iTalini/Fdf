/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 20:04:18 by dkalashn          #+#    #+#             */
/*   Updated: 2017/11/22 20:08:26 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *res;
	unsigned char *tmp;

	tmp = (unsigned char *)src;
	res = (unsigned char *)dst;
	if (src < dst)
	{
		while (len--)
			res[len] = tmp[len];
	}
	else
		ft_memcpy(res, tmp, len);
	return (dst);
}
