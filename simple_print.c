//
// Created by denys on 15.11.17.
//

#include <asm/ioctls.h>
#include <sys/ioctl.h>
#include "ft_ls.h"

static int  line_in_range(int array)
{

}

static void make_lines(t_node *node, int width)
{
    t_file  *file;

    while (node)
    {
        file = (t_file*)node->data;
        ft_printf("%s  ", file->file_name);
        node = node->next;
        if (node == NULL)
            ft_putendl("");
    }
}

void simple_print(t_doubly_list *list)
{
    struct winsize  w;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w); //w.ws_col
    make_lines(list->head, 50);
}