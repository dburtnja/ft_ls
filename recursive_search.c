/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 12:39:11 by dburtnja          #+#    #+#             */
/*   Updated: 2018/01/13 12:39:52 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		file_is_directory(t_file *file)
{
	if (ft_strcmp(file->file_name, ".") == 0)
		return (FALSE);
	if (ft_strcmp(file->file_name, "..") == 0)
		return (FALSE);
	if (S_ISDIR(file->info.st_mode))
		return (TRUE);
	return (FALSE);
}

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
        if (file_is_directory(file))
        {
			new_directory = new_dir(file->file_name, dir->dir_with_path);
			new_directory->info = file->info;
            add_to_back(ls->dirs, new_node(new_directory, sizeof(t_dir)));
            recursive_search(ls, ls->dirs->tail->data);
        }
        node = node->next;
    }
}
