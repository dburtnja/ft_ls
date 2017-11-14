//
// Created by denys on 10/21/17.
//

#include "ft_ls.h"

t_dir   *new_dir(char *name, char *path)
{
    t_dir   *dir;

    dir = ft_memalloc_error(sizeof(t_dir));
    dir->dir_name = name;
    if (ft_strcmp(".", name) == 0)
        dir->dir_with_path = path;
    else
        dir->dir_with_path = path;
//        dir->dir_with_path = ft_format("%s/%s", path, name[0] == '.' ? &(name[2]) : name);
    return (dir);
}