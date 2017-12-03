
#include "ft_ls.h"


static void add_files_to_dir(t_ls *ls, DIR *dir, t_dir *directory)
{
    struct dirent   *entry;
    t_file*         new_file_var;

    directory->files = new_doubly_list(NULL, &by_name, ls->flags & FLAG_r, TYPE_DIR);
    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_name[0] != '.' || ls->flags & FLAG_a)
        {
            new_file_var = new_file(ft_strdup(entry->d_name), directory->dir_with_path);
            open_file(ls, new_file_var);
            ft_add_with_sort(directory->files, new_node(new_file_var, sizeof(t_file)));
        }
    }
}

int open_directory(t_dir *directory, t_ls *ls)
{
    DIR             *dir;

    if ((dir = opendir(directory->dir_with_path)) == NULL)
        perror(ft_format("ft_ls: cannot excess d'%s'", directory->dir_with_path));
    add_files_to_dir(ls, dir, directory);
    closedir(dir);
}