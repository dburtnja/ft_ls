
#include <time.h>
#include "ft_ls.h"
#include "libft/ft_printf/ft_printf.h"
#include "libft/libft.h"

void    debug_ls(t_ls *ls)
{
    t_node  *node;
    t_node  *node_file;
    t_file  *file;

    ft_putendl("=====================START PRINT LS=======================");
    ft_printf("Flags: %016b\n", ls->flags);
    node = ls->dirs->head;
    while (node)
    {
        ft_putendl(((t_dir*)node->data)->dir_with_path);
        node_file = ((t_dir*)node->data)->files->head;
        while (node_file)
        {
            file = (t_file *)node_file->data;
//            ft_printf(" %.12s %s\n", &(ctime(&(file->info.st_ctim.tv_sec))[4]), file->file_name);
            node_file = node_file->next;
        }
        node = node->next;
    }
    ft_putendl("=====================END PRINT LS=======================");
}

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
    ls->main_dir_name = argv[1];
    if (argc > 0)
        read_arguments(ls, &argv[2], argc - 2);
    through_all_input(ls);
//    debug_ls(ls);
    sort_before_print(ls);
    print_ls(ls);
    return (0);
}

//int main()
//{
//    t_doubly_list *list = new_doubly_list(new_node("Denys", 6));
//    add_to_front(list, new_node("ZACER", 5));
//    add_to_front(list, new_node("Ivan", 5));
//    add_to_front(list, new_node("5ZACE", 5));
//
//    t_node *node;
//
//    node = list->head;
//    while (node)
//    {
//        ft_putendl(node->data);
//        node = node->next;
//    }
//    ft_printf("return = %d\n", ft_sort_doubly_list(list, &compare_list));
//
//
//    node = list->head;
//    while (node)
//    {
//        ft_putendl(node->data);
//        node = node->next;
//    }
//}