//
// Created by denys on 10/22/17.
//

#include "ft_ls.h"

int open_directory(t_dir *directory, t_ls *ls)
{
    DIR             *dir;
    struct dirent   *entry;
    char            *full_dir_name;

//    ft_putendl(directory->dir_name);
//    ft_putendl(directory->dir_with_path);
    full_dir_name = ft_strjoin(ls->main_dir_name, directory->dir_with_path);
    if ((dir = opendir(full_dir_name)) == NULL) {
        perror(ft_format("ft_ls: cannot excess d'%s'", directory->dir_name));
        ft_putendl(full_dir_name);
    }
    directory->files = new_doubly_list(NULL);
    while ((entry = readdir(dir)) != NULL)
    {
        t_file* new_file_var;
        if (entry->d_name[0] != '.' || ls->flags & FLAG_a)
        {
            new_file_var = new_file(ft_strdup(entry->d_name), directory->dir_with_path);
            open_file(ls, new_file_var);
//            ft_putendl(new_file_var->file_name);
//            ft_putendl(new_file_var->file_with_path);
            add_to_back(directory->files, new_node(new_file_var, sizeof(t_file)));
        }
    }
    ft_strdel(&full_dir_name);
    closedir(dir);
//    if (ls->flags & FLAG_a)
//    {
//        add_to_front(directory->files, new_node(new_file("..", directory->dir_with_path), sizeof(t_file)));
//        add_to_front(directory->files, new_node(new_file(".", directory->dir_with_path), sizeof(t_file)));
//    }
}