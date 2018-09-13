/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 18:10:02 by dkalashn          #+#    #+#             */
/*   Updated: 2017/11/22 19:39:32 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*res;
	int		l;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	l = ft_strlen(s) - 1;
	while (l >= 0 && (s[l] == ' ' || s[l] == '\n' || s[l] == '\t'))
		l--;
	j = l - i;
	if (j < 0 || ft_strlen(s) == 0)
		return (ft_strnew(1));
	res = ft_strnew(j + 1);
	if (!res)
		return (NULL);
	l = -1;
	while (++l < (j + 1))
		res[l] = s[i + l];
	return (res);
}
