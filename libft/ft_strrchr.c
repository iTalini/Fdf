/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:36:50 by dkalashn          #+#    #+#             */
/*   Updated: 2017/11/09 18:47:01 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*res;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] == c)
			res = &s[i];
		i++;
	}
	if (c == '\0')
		res = &s[i];
	return ((char *)res);
}
