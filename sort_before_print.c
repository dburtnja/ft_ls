//
// Created by denys on 13.11.17.
//

#include "ft_ls.h"

static char *remove_dot(char *name)
{
    if (ft_strcmp(name, ".") || ft_strcmp(name, ".."))
        return name;
    while (*name == '.')
        name++;
    return name;
}

static int  by_name(t_node *first, t_node *second, int type)
{
    char    *first_name;
    char    *second_name;

    if (type == TYPE_DIR)
    {
        first_name = ft_strmap(((t_dir*)first->data)->dir_with_path, &ft_tolower);
        second_name = ft_strmap(((t_dir*)second->data)->dir_with_path, &ft_tolower);
    }
    else if (type == TYPE_FILE)
    {
        first_name = ft_strmap(((t_file *) first->data)->file_name, &ft_tolower);
        second_name = ft_strmap(((t_file *) second->data)->file_name, &ft_tolower);
    }
    if (type == TYPE_FILE || type == TYPE_DIR)
        return ft_strcmp(remove_dot(first_name), remove_dot(second_name));
    else
        return (0);
}

static void select_sort_type(int flags, t_doubly_list *list, int dir)
{
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