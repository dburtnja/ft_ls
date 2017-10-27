//
// Created by denys on 10/22/17.
//

#include "ft_ls.h"

void    recursive_search(t_ls *ls, t_dir *dir)
{
    t_node  *node;
    t_file  *file;
    t_dir   *new_directory;

    open_directory(dir, ls);
    node = dir->files->head;
    while (node)
    {
        file = (t_file*)(node->data);
        open_file(file);
        if (file->info.st_mode & S_IFDIR)
        {
            if (dir->dir_name[ft_strlen(dir->dir_name) - 1] == '/')
                new_directory = new_dir(ft_format("%s%s", dir->dir_name, file->file_name), ls->main_dir_name);
            else
                new_directory = new_dir(ft_format("%s/%s", dir->dir_name, file->file_name), ls->main_dir_name);
            add_to_back(ls->dirs, new_node(new_directory, sizeof(t_dir)));
            recursive_search(ls, ls->dirs->tail->data);
        }
        node = node->next;
    }
}