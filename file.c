//
// Created by denys on 10/22/17.
//

#include "ft_ls.h"

t_file  *new_file(char *name, char *path)
{
    t_file  *file;

    file = ft_memalloc_error(sizeof(t_file));
    file->file_name = name;
    file->file_with_path = ft_format("%s/%s", path, name);
    return (file);
}

void    open_file(t_file *file)
{
    int result;

    result = stat(file->file_with_path, &(file->info));
    if (result != 0)
        perror(ft_format("ft_ls: cannot excess f'%s'", file->file_name));
}