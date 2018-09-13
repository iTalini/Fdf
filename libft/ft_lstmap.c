/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 21:28:09 by dkalashn          #+#    #+#             */
/*   Updated: 2017/11/22 20:13:54 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *head;

	if (!lst || !f)
		return (NULL);
	head = f(lst);
	new = head;
	while (lst->next)
	{
		lst = lst->next;
		new->next = f(lst);
		new = new->next;
	}
	return (head);
}
