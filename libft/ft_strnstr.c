/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:13:24 by dkalashn          #+#    #+#             */
/*   Updated: 2017/11/20 20:08:50 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *ned, size_t len)
{
	size_t		i;
	size_t		j;
	const char	*res;

	i = 0;
	j = ft_strlen(ned);
	if (hay[i] == '\0' && ned[i] == '\0')
		return ((char *)hay);
	while (hay[i] && i < len)
	{
		if ((j + i) <= len && ft_strncmp(&hay[i], ned, j) == 0)
		{
			res = &hay[i];
			return ((char *)res);
		}
		i++;
	}
	return (0);
}
