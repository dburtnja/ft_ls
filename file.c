/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:54:28 by dburtnja          #+#    #+#             */
/*   Updated: 2018/01/13 14:55:13 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*new_file(char *name, char *path)
{
	t_file	*file;

	file = ft_memalloc_error(sizeof(t_file));
	file->file_name = name;
	file->file_with_path = ft_format("%s/%s", path, name);
	if (((unsigned char*)file->file_name)[0] > 127)
		file->name_len = (int)ft_strlen(file->file_name) / 2;
	else
		file->name_len = (int)ft_strlen(file->file_name);
	return (file);
}

void	open_file(t_file *file)
{
	int		result;

	result = stat(file->file_with_path, &(file->info));
	if (result != 0)
		result = lstat(file->file_with_path, &(file->info));
	if (result != 0)
	{
		perror(ft_format("ft_ls: cannot excess f'%s'", file->file_name));
		exit(0);
	}
}
