/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 04:25:14 by dkalashn          #+#    #+#             */
/*   Updated: 2017/10/29 16:31:21 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *ar;
	int i;
	int j;

	if (max <= min)
		return (0);
	ar = (int *)malloc(sizeof(int) * (max - min));
	if (ar == 0)
		return (0);
	i = -1;
	j = max - min;
	while (++i < j)
	{
		ar[i] = min;
		min++;
	}
	return (ar);
}
