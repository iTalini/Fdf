/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:30:33 by dkalashn          #+#    #+#             */
/*   Updated: 2017/11/22 19:33:00 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	i;
	char			*a;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	a = ft_strnew(len);
	if (!a)
		return (NULL);
	while (i < len)
	{
		a[i] = (*f)(i, s[i]);
		i++;
	}
	a[i] = '\0';
	return (a);
}
