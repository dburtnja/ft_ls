//
// Created by denys on 9/11/17.
//

#include "libft.h"

t_doubly_list   *new_doubly_list()
{
    t_doubly_list   *ret;

    ret = (t_doubly_list *)ft_memalloc_error(sizeof(t_doubly_list));
    return ret;
}

t_node          *new_node(void *data, size_t data_size)
{
    t_node  *node;

    node = (t_node*)ft_memalloc_error(sizeof(t_node));
    node->data = data;
    node->data_size = data_size;
    return node;
}

void            delete_doubly_list(t_doubly_list **list)
{
    t_node  *p;
    t_node  *buf;

    p = (*list)->head;
    while (p)
    {
        buf = p;
        p = p->next;
        ft_memdel((void **) &buf);
    }
    ft_memdel((void **) list);
}

void            add_to_front(t_doubly_list *list, t_node *node)
{
    node->next = list->head;
    list->head = node;
    if (node->next == NULL)
        list->tail = node;
    else
        node->next->prev = node;
    (list->size)++;
}

void            add_to_back(t_doubly_list *list, t_node *node)
{
    node->prev = list->tail;
    list->tail = node;
    if (node->prev == NULL)
        list->head = node;
    else
        node->prev->next = node;
    (list->size)++;
}