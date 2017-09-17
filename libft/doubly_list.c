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

int             add_to_position(t_doubly_list *list, size_t pos, t_node *node) {
    size_t from_current;
    size_t from_end;

    if (pos > list->size)
        return FALSE;
    from_current = (size_t) abs((int) (pos - list->current_id));
    from_end = list->size - pos;
    if (pos < from_current && pos < from_end) {
        if (add_from_start(list, pos, node) == pos)
            return TRUE;
    }
    if (from_current < pos && from_current < from_end)
    {
        if (add_from_current(list, pos, node) == pos)
            return TRUE;
    }
    if (add_from_end(list, pos, node) == pos)
        return TRUE;
    return FALSE;
}