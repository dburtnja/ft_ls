//
// Created by denys on 13.11.17.
//

#include "libft.h"

static int  replace_nodes(t_node *first, t_node *second)
{
    void    *buf_data;
    size_t  buf_size;

    if (!first || !second)
        return FALSE;
    buf_data = first->data;
    buf_size = first->data_size;
    first->data = second->data;
    first->data_size = second->data_size;
    second->data = buf_data;
    second->data_size = buf_size;
    return TRUE;
}

int ft_sort_doubly_list(t_doubly_list *list, int (*f)(t_node *, t_node *, int), int reverse, int type)
{
    int     is_sort;
    t_node  *node;

    is_sort = FALSE;
    while (!is_sort)
    {
        node = list->head;
        is_sort = TRUE;
        while (node && node->next)
        {
            if ((reverse ? -f(node, node->next, type) : f(node, node->next, type)) > 0)
            {
                is_sort = FALSE;
                if (replace_nodes(node, node->next) == FALSE)
                    return FALSE;
            }
            node = node->next;
        }
    }
    return TRUE;
}