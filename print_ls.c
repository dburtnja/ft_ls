
#include <asm/ioctls.h>
#include <sys/ioctl.h>
#include "ft_ls.h"

static void print_dirs(t_doubly_list *dirs, int flags)
{
    struct winsize  w;
    size_t          width;
    t_node          *node;
    t_dir           *dir;

	width = ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0 ? w.ws_col : 0;
    node = dirs->head;
    while (node)
    {
        dir = (t_dir*)node->data;
        if (dirs->size != 1)
            ft_printf("%s:\n", dir->dir_with_path);
        if (flags & FLAG_l)
            list_print(dir);
        else
            simple_print(dir->files, width);
        node = node->next;
        if (node != NULL)
            ft_putendl("");
    }
}

void    print_ls(t_ls *ls)
{
    print_dirs(ls->dirs, ls->flags);
}