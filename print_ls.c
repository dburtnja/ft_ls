//
// Created by denys on 10/22/17.
//

#include "ft_ls.h"

static void print_files(t_doubly_list *files, int flags)
{
    t_node  *node;
    t_file  *file;

    node = files->head;
    while (node)
    {
        file = (t_file*)node->data;
        ft_printf("%s  ", file->file_name);
        node = node->next;
        if (node == NULL)
            ft_putendl("");
    }
}

static void print_dirs(t_doubly_list *dirs, int flags)
{
    int     dir_name;
    t_node  *node;
    t_dir   *dir;

    dir_name = dirs->size == 1 ? FALSE : TRUE;
    node = dirs->head;
    while (node)
    {
        dir = (t_dir*)node->data;
        if (dir_name)
            ft_printf(".%s:\n", dir->dir_with_path);
        print_files(dir->files, flags);
        node = node->next;
        if (node != NULL)
            ft_putendl("");
    }
}

void    print_ls(t_ls *ls)
{
    print_dirs(ls->dirs, ls->flags);
}