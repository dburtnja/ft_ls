

#include <dirent.h>
#include <stdio.h>
#include "ft_ls.h"
#include "libft/ft_printf/ft_printf.h"
#include "libft/libft.h"

void    print_ls(t_ls *ls)
{
    t_node  *node;

    ft_printf("Flags: %016b\n", ls->flags);
    node = ls->dirs->head;
    while (node)
    {
        ft_putendl(((t_dir*)node->data)->dir_name);
        node = node->next;
    }
}

int     main(int argc, char **argv)
{
    t_ls    *ls;


    ls = (t_ls *)ft_memalloc_error(sizeof(t_ls));
    ls->main_dir_name = argv[1];
    if (argc > 0)
        read_arguments(ls, &argv[2], argc - 2);
    print_ls(ls);


    DIR             *dir;
    struct dirent   *entry;
    char            *dir_name;

    dir_name = ((t_dir *)ls->dirs->head->data)->dir_name;
    if ((dir = opendir(dir_name)) == NULL) {
        perror(ft_strjoin("Fail to open: ", dir_name));
        exit(-1);
    }
    while ((entry = readdir(dir)) != NULL)
        ft_printf("INO: %d; NAME: %s; TYPE: %d; RECLEN: %d\n", entry->d_ino, entry->d_name, entry->d_type, entry->d_reclen);
    if (argc > 0)
        ft_putendl(argv[1]);
    return (0);
}