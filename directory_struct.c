//
// Created by denys on 10/21/17.
//

#include "ft_ls.h"

t_dir   *new_dir(char *name)
{
    t_dir   *dir;

    dir = ft_memalloc_error(sizeof(t_dir));
    dir->dir_name = name;
    return (dir);
}