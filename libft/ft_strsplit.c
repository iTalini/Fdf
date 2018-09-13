/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:31:21 by dkalashn          #+#    #+#             */
/*   Updated: 2017/11/28 21:56:39 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			count(char const *s, char c)
{
	int i;
	int	co;

	i = 0;
	co = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			co++;
		i++;
	}
	return (co);
}

static int			count_w(char **sm, char c)
{
	int	i;
	int c_w;

	c_w = 0;
	i = 0;
	while (sm[0][i] == c)
		i++;
	while (sm[0][i] != c && sm[0][i] != '\0')
	{
		c_w++;
		i++;
	}
	*sm = *sm + i - 1;
	return (c_w);
}

static char			**write_ar(char **res, const char *s, char c, int j)
{
	int i;
	int z;
	int k;

	i = 0;
	k = 0;
	while (i < j)
	{
		z = 0;
		while (s[k] == c)
			k++;
		while (s[k] != c && s[k])
		{
			res[i][z] = s[k];
			k++;
			z++;
		}
		res[i][z] = '\0';
		i++;
	}
	return (res);
}

static void			s_free_ar(char **res, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(res[i]);
		i++;
	}
	free(res);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	char	*sm;
	int		j;

	if (!s)
		return (NULL);
	i = -1;
	sm = (char *)s;
	j = count(s, c);
	if (!(res = (char **)malloc(sizeof(char *) * (j + 1))))
		return (NULL);
	while (++i < j)
	{
		if (!(res[i] = (char *)malloc(sizeof(char) * (count_w(&sm, c) + 1))))
		{
			s_free_ar(res, (j + 1));
			return (NULL);
		}
	}
	res = write_ar(res, s, c, j);
	res[i] = NULL;
	return (res);
}
