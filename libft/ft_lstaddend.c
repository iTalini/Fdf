/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:29:02 by dkalashn          #+#    #+#             */
/*   Updated: 2017/11/23 18:35:12 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list *current;

	if (!new)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	current = *alst;
	while (current->next)
		current = current->next;
	current->next = new;
}
