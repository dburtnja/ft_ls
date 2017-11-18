//
// Created by denys on 10/22/17.
//

#include "ft_ls.h"


static void add_files_to_dir(t_ls *ls, DIR *dir, t_dir *directory)
{
    struct dirent   *entry;
    t_file*         new_file_var;

    directory->files = new_doubly_list(NULL);
    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_name[0] != '.' || ls->flags & FLAG_a)
        {
            new_file_var = new_file(ft_strdup(entry->d_name), directory->dir_with_path);
            open_file(ls, new_file_var);
            add_to_back(directory->files, new_node(new_file_var, sizeof
                    (t_file)));
        }
    }
}

int open_directory(t_dir *directory, t_ls *ls)
{
    DIR             *dir;
    char            *full_dir_name;

    full_dir_name = ft_strjoin(ls->main_dir_name, directory->dir_with_path);
    if ((dir = opendir(full_dir_name)) == NULL)
    {
        ft_putendl(full_dir_name);
        perror(ft_format("ft_ls: cannot excess d'%s'", directory->dir_name));
    }
    add_files_to_dir(ls, dir, directory);
    ft_strdel(&full_dir_name);
    closedir(dir);
}