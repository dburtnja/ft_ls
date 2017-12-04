
#include <time.h>
#include "ft_ls.h"
#include "libft/ft_printf/ft_printf.h"
#include "libft/libft.h"

static void through_all_input(t_ls *ls)
{
    t_node  *node;
    size_t  size;

    node = ls->dirs->head;
    size = ls->dirs->size;
    /* use size, because in recursion i will add elements to list */
    while (size != 0)
    {
        if (ls->flags & FLAG_R)
            recursive_search(ls, node->data);
        else
            open_directory(node->data, ls);
        node = node->next;
        size--;
    }
}

int     main(int argc, char **argv)
{
    t_ls    *ls;

    ls = (t_ls *)ft_memalloc_error(sizeof(t_ls));
    read_arguments(ls, &argv[1], argc - 1);
	through_all_input(ls);
    sort_before_print(ls);
    print_ls(ls);
    return (0);
}