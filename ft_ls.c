

#include <dirent.h>
#include <stdio.h>
#include "ft_ls.h"
#include "libft/ft_printf/ft_printf.h"
#include "libft/libft.h"

int     main(int argc, char **argv)
{
    t_ls    *ls;

    if (argc > 0)
    {
        ls = (t_ls *)ft_memalloc_error(sizeof(t_ls));
        ls->start_path = argv[1];
        read_arguments(ls, &argv[2], argc - 2);
    }

    return (0);
}

//DIR             *dir;
//struct dirent   *entry;
//
//
//if ((dir = opendir(argv[1])) == NULL) {
//perror(ft_strjoin("Fail to open: ", argv[1]));
//exit(-1);
//}
//while ((entry = readdir(dir)) != NULL)
//ft_printf("INO: %d; NAME: %s; TYPE: %d; RECLEN: %d\n", entry->d_ino, entry->d_name, entry->d_type, entry->d_reclen);
//if (argc > 0)
//ft_putendl(argv[1]);