/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 02:02:04 by dkalashn          #+#    #+#             */
/*   Updated: 2017/11/28 18:23:50 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *src)
{
	int		len;
	char	*str;
	int		i;

	len = ft_strlen(src);
	i = -1;
	str = (char *)malloc(sizeof(char) * len + 1);
	ft_bzero(str, len + 1);
	if (str == 0)
		return (0);
	while (++i < len)
		str[i] = src[i];
	str[len] = '\0';
	return (str);
}
