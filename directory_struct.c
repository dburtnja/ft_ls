//
// Created by denys on 10/21/17.
//

#include "ft_ls.h"

t_dir *new_dir(char *name, char *path)
{
    t_dir   *dir;
	size_t	len;

    dir = ft_memalloc_error(sizeof(t_dir));
	len = ft_strlen(name);
	if (name[len - 1] == '/')
		name[len - 1] = 0;
    if (name[0] == '/' || (name[0] == '.' && name[1] == '.'))
        dir->dir_with_path = name;
    else if (path)
        dir->dir_with_path = ft_format("%s/%s", path, name);
    else
        dir->dir_with_path = ".";
    return (dir);
}