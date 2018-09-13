/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:20:13 by dkalashn          #+#    #+#             */
/*   Updated: 2017/11/23 18:39:16 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstcount(t_list *alst)
{
	t_list	*current;
	int		i;

	i = 0;
	if (!alst)
		return (0);
	current = alst;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}
