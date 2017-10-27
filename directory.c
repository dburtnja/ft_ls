//
// Created by denys on 10/22/17.
//

#include "ft_ls.h"

int open_directory(t_dir *directory, t_ls *ls)
{
    DIR             *dir;
    struct dirent   *entry;

    ft_putendl(directory->dir_name);
    if ((dir = opendir(directory->dir_with_path)) == NULL) {
        perror(ft_format("ft_ls: cannot excess d'%s'", directory->dir_name));
        ft_putendl(directory->dir_with_path);}
    directory->files = new_doubly_list(NULL);
    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_name[0] != '.')
            add_to_back(directory->files, new_node(new_file(entry->d_name, directory->dir_with_path), sizeof(t_file)));
    }
    closedir(dir);
    if (ls->flags & FLAG_a)
    {
        add_to_front(directory->files, new_node(new_file("..", directory->dir_with_path), sizeof(t_file)));
        add_to_front(directory->files, new_node(new_file(".", directory->dir_with_path), sizeof(t_file)));
    }
}