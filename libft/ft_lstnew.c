/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkalashn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:04:38 by dkalashn          #+#    #+#             */
/*   Updated: 2017/11/22 20:14:30 by dkalashn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *head;

	head = (t_list *)malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->next = NULL;
	if (!content)
	{
		head->content = NULL;
		head->content_size = 0;
		return (head);
	}
	head->content = malloc(sizeof(void *) * content_size);
	ft_memcpy(head->content, content, content_size);
	head->content_size = content_size;
	return (head);
}
