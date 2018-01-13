/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_before_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:16:13 by dburtnja          #+#    #+#             */
/*   Updated: 2018/01/13 13:16:15 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	select_sort_type(int flags, t_doubly_list *list, int dir)
{
	if (flags & FLAG_T)
		ft_sort_doubly_list(list, &by_mod_time, flags & FLAG_R, dir);
	else
		ft_sort_doubly_list(list, &by_name, flags & FLAG_R, dir);
}

void		sort_before_print(t_ls *ls)
{
	t_node	*node;

	select_sort_type(ls->flags, ls->dirs, TYPE_DIR);
	node = ls->dirs->head;
	while (node)
	{
		select_sort_type(ls->flags, ((t_dir*)(node->data))->files, TYPE_FILE);
		node = node->next;
	}
}
