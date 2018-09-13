/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:45:54 by dkalashn          #+#    #+#             */
/*   Updated: 2017/11/09 18:49:01 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hay, const char *ned)
{
	int			i;
	int			j;
	const char	*res;

	i = 0;
	j = ft_strlen(ned);
	if (hay[i] == '\0' && ned[i] == '\0')
		return ((char *)hay);
	while (hay[i])
	{
		if (ft_strncmp(&hay[i], ned, j) == 0)
		{
			res = &hay[i];
			return ((char *)res);
		}
		i++;
	}
	return (0);
}
