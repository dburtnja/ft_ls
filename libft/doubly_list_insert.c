//
// Created by denys on 9/17/17.
//

#include "libft.h"

void     insert_before(t_node *node_in_list, t_node *node, t_doubly_list *list, size_t pos)
{
    node->next = node_in_list;
    node->prev = node_in_list->prev;
    if (node->prev)
        node->prev->next = node;
    else
        list->head = node;//todo check
    if (node->next)
        node->next->prev = node;
    list->current = node;
    list->current_id = pos;
    list->size++;
}

void    insert_in_empty