/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:14:11 by dkalashn          #+#    #+#             */
/*   Updated: 2017/11/22 19:42:36 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		len;
	int		i;
	char	*a;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	a = ft_strnew(len);
	if (!a)
		return (NULL);
	while (i < len)
	{
		a[i] = (*f)(s[i]);
		i++;
	}
	return (a);
}
