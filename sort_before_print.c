//
// Created by denys on 13.11.17.
//

#include "ft_ls.h"

static void select_sort_type(int flags, t_doubly_list *list, int dir)
{
    if (flags & FLAG_t)
        ft_sort_doubly_list(list, &by_mod_time, flags & FLAG_r, dir);
    else
        ft_sort_doubly_list(list, &by_name, flags & FLAG_r, dir);
}

void        sort_before_print(t_ls *ls)
{
    t_node  *node;

    select_sort_type(ls->flags, ls->dirs, TYPE_DIR);
    node = ls->dirs->head;
    while (node)
    {
        select_sort_type(ls->flags, ((t_dir*)(node->data))->files, TYPE_FILE);
        node = node->next;
    }
}