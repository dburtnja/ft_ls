//
// Created by denys on 10/22/17.
//

#include <asm/ioctls.h>
#include <sys/ioctl.h>
#include "ft_ls.h"

static void print_dirs(t_doubly_list *dirs, int flags)
{
    int             dir_name;
    struct winsize  w;
    size_t          width;
    t_node          *node;
    t_dir           *dir;

    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0)
        width = w.ws_col; //w.ws_col
    else
        width = 0;
    width = 50;
    dir_name = dirs->size == 1 ? FALSE : TRUE;
    node = dirs->head;
    while (node)
    {
        dir = (t_dir*)node->data;
        if (dir_name)
            ft_printf(".%s:\n", dir->dir_with_path);
        if (flags & FLAG_l)
            ft_putendl("PRINT AS LIST");
        else
            simple_print(dir->files, width);
        node = node->next;
        if (node != NULL)
            ft_putendl("");
    }
//    ft_putendl("");
}

void    print_ls(t_ls *ls)
{
    print_dirs(ls->dirs, ls->flags);
}