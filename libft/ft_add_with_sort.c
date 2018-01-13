/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_with_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 09:36:23 by dburtnja          #+#    #+#             */
/*   Updated: 2018/01/13 09:54:45 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		add_to_list(t_doubly_list *sort_list, t_node *p, t_node *node)
{
	int	sort_val;
	int rev;

	rev = sort_list->revers;
	while (p->next)
	{
		sort_val = sort_list->sort_func(p, node, sort_list->sort_data);
		if (sort_val > 0 || (rev && sort_val < 0))
			break ;
		p = p->next;
	}
	add_after_node(sort_list, p->prev, node);
}

static void		add_to_existing(t_doubly_list *sort_list, t_node *node)
{
	t_node	*p_node;
	int		compare_result;

	p_node = sort_list->head;
	compare_result = sort_list->sort_func(p_node, node, sort_list->sort_data);
	compare_result = sort_list->revers ? -compare_result : compare_result;
	if (sort_list->size == 1 && compare_result > 0)
		add_to_front(sort_list, node);
	else if (sort_list->size == 1 && compare_result <= 0)
		add_to_back(sort_list, node);
	else
		add_to_list(sort_list, sort_list->head, node);
}

void			ft_add_with_sort(t_doubly_list *sort_list, t_node *node)
{
	if (sort_list->sort == FALSE)
	{
		ft_putendl("Can't add node to not sorted list");
		exit(1);
	}
	sort_list->sort = FALSE;
	if (sort_list->size == 0)
		add_to_front(sort_list, node);
	else
		add_to_existing(sort_list, node);
	sort_list->sort = TRUE;
}
