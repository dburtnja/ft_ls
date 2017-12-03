//
// Created by denys on 10/21/17.
//

#include "ft_ls.h"

t_dir *new_dir(char *name)
{
    t_dir   *dir;

    dir = ft_memalloc_error(sizeof(t_dir));
    dir->dir_name = name;
    if (name[0] == '/')
        dir->dir_with_path = name;
    else
        dir->dir_with_path = ft_strjoin("./", name);
    return (dir);
}