/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_list_nodes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 09:55:27 by dburtnja          #+#    #+#             */
/*   Updated: 2018/01/13 09:55:29 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	add_to_front(t_doubly_list *list, t_node *node)
{
	if (list->sort)
	{
		ft_putendl("The list is sorted. Please use ft_add_with_sort function");
		exit(1);
	}
	node->next = list->head;
	list->head = node;
	if (node->next == NULL)
		list->tail = node;
	else
		node->next->prev = node;
	(list->size)++;
}

void	add_to_back(t_doubly_list *list, t_node *node)
{
	if (list->sort)
	{
		ft_putendl("The list is sorted. Please use ft_add_with_sort function");
		exit(1);
	}
	node->prev = list->tail;
	list->tail = node;
	if (node->prev == NULL)
		list->head = node;
	else
		node->prev->next = node;
	(list->size)++;
}

int		add_after_node(t_doubly_list *list, t_node *after, t_node *node)
{
	t_node	*buf;

	if (after == NULL)
		return (FALSE);
	buf = after->next;
	after->next = node;
	node->prev = after;
	if (buf)
	{
		buf->prev = node;
		node->next = buf;
	}
	(list->size)++;
	return (TRUE);
}
