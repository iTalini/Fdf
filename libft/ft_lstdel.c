/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 21:33:17 by dkalashn          #+#    #+#             */
/*   Updated: 2017/11/23 15:58:37 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *current;

	if (!alst || !del)
		return ;
	tmp = *alst;
	current = tmp;
	while (current)
	{
		tmp = current->next;
		(*del)(current->content, current->content_size);
		free(current);
		current = tmp;
	}
	*alst = NULL;
}
