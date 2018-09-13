/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:46:08 by dkalashn          #+#    #+#             */
/*   Updated: 2017/11/21 21:52:41 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len_s;
	size_t len_d;
	size_t i;

	i = -1;
	len_s = ft_strlen(src);
	len_d = ft_strlen(dst);
	if (size <= len_d)
		return (len_s + size);
	while (src[++i] && (len_d + i + 1) < (size))
		dst[len_d + i] = src[i];
	dst[len_d + i] = '\0';
	return (len_s + len_d);
}
