//
// Created by denys on 13.11.17.
//

#include "ft_ls.h"

static int	my_strcmp(const char *s1, const char *s2)
{
    size_t  first;
    size_t  second;

    first = 0;
    second = 0;
    while (s1[first] == s2[second] && s1[first] != '\0' && s2[second] != '\0')
    {
        first++;
        second++;
        while (s1[first] == '.')
            first++;
        while (s2[second] == '.')
            second++;
    }
    if (s1[first] - s2[second] == 0)
        return (int) (first - second);
    return s1[first] - s2[second];
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
        return my_strcmp(first_name, second_name);
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