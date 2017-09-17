//
// Created by denys on 9/17/17.
//

#include "libft.h"

static t_node   *get_from_tail_to_head(t_doubly_list *list, size_t pos)
{
    t_node  *p;
    size_t  i;

    i = list->size;
    p = list->tail;
    while (p && i >= pos)
    {
        p = p->prev;
        i--;
    }
    if (i == pos)
        return p;
    return NULL;
}

static t_node   *get_from_head_to_tail(t_doubly_list *list, size_t pos)
{
    t_node  *p;
    size_t  i;

    i = 0;
    p = list->head;
    while (p && i <= pos)
    {
        p = p->next;
        i++;
    }
    if (i == pos)
        return p;
    return NULL;
}

size_t          add_from_start(t_doubly_list *list, size_t pos, t_node *node)
{
    t_node  *p;

    if ((p = get_from_head_to_tail(list, pos)) != NULL)
    {
        insert_before(p, node, list, pos);
        return pos;
    }
    return 0;
}

size_t          add_from_end(t_doubly_list *list, size_t pos, t_node *node)
{
    t_node  *p;

    if ((p = get_from_tail_to_head(list, pos)) != NULL)
    {
        insert_before(p, node, list, pos);
        return pos;
    }
    return 0;
}

size_t          add_from_current(t_doubly_list *list, size_t pos, t_node *node)
{
    if (list->current_id - pos > 0)
        return add_from_end(list, pos, node);
    else
        return add_from_start(list, pos, node);
}