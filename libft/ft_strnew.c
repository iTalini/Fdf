/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:23:35 by dkalashn          #+#    #+#             */
/*   Updated: 2017/11/23 17:39:28 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*res;
	size_t	i;

	i = 0;
	if (!(res = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(res, size + 1);
	while (i <= size)
	{
		res[i] = '\0';
		i++;
	}
	return (res);
}
