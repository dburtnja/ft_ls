//
// Created by denys on 13.11.17.
//

#include "ft_ls.h"

static  int compare_list(t_node *first, t_node *second)
{
    return ft_strcmp((char*)(first->data), (char*)(second->data));
}

void        sort_before_print(t_ls *ls)
{
    ft_sort_doubly_list(ls->dirs, &compare_list);
}