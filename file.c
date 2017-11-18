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
    file->name_len = (int)ft_strlen(file->file_name);
    return (file);
}

void    open_file(t_ls *ls, t_file *file)
{
    int     result;
    char    *full_file_name;

    full_file_name = ft_strjoin(ls->main_dir_name, file->file_with_path);
    result = stat(full_file_name, &(file->info));
    if (result != 0)
        result = lstat(full_file_name, &(file->info));
    if (result != 0)
    {
        perror(ft_format("ft_ls: cannot excess f'%s'", file->file_name));
        exit(0);
    }
    ft_strdel(&full_file_name);
}