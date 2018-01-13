/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubly_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 09:31:08 by dburtnja          #+#    #+#             */
/*   Updated: 2018/01/13 09:51:36 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node			*new_node(void *data, size_t data_size)
{
	t_node	*node;

	node = (t_node*)ft_memalloc_error(sizeof(t_node));
	node->data = data;
	node->data_size = data_size;
	return (node);
}

void			delete_doubly_list(t_doubly_list **list)
{
	t_node	*p;
	t_node	*buf;

	p = (*list)->head;
	while (p)
	{
		buf = p;
		p = p->next;
		ft_memdel((void **)&buf);
	}
	ft_memdel((void **)list);
}

t_doubly_list	*new_doubly_list(t_node *node,
		int (*sort_func)(t_node *, t_node *, int), int sort_data, int revers)
{
	t_doubly_list	*ret;

	ret = (t_doubly_list *)ft_memalloc_error(sizeof(t_doubly_list));
	if (node != NULL)
	{
		ret->head = node;
		ret->tail = node;
		ret->size = 1;
	}
	ret->sort_func = sort_func;
	ret->sort_data = sort_data;
	ret->revers = revers;
	if (ret->sort_func != NULL)
		ret->sort = TRUE;
	return (ret);
}
