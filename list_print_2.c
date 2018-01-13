/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_print_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 12:46:31 by dburtnja          #+#    #+#             */
/*   Updated: 2018/01/13 13:31:13 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "ft_ls.h"

static void	update_column_sizes(int *column_sizes, char **line_array)
{
	int	i;
	int size;

	i = 0;
	while (line_array[i])
	{
		size = (int)ft_strlen(line_array[i]);
		column_sizes[i] = column_sizes[i] < size ? size : column_sizes[i];
		i++;
	}
}

static char	**create_simple_line_array(t_file *file, int *column_sizes)
{
	char	**line_array;

	line_array = ft_memalloc_error(sizeof(char *) * 8);
	line_array[0] = read_chmod(file->info, file->file_with_path);
	line_array[1] = ft_itoa((int)file->info.st_nlink);
	line_array[2] = get_group_name(file->info.st_gid);
	line_array[3] = get_user_name(file->info.st_uid);
	line_array[4] = ft_itoa((int)file->info.st_size);
	line_array[5] = ft_strdup(ctime(&(file->info.st_mtimespec.tv_sec)));
	line_array[6] = file->file_name;
	update_column_sizes(column_sizes, line_array);
	return (line_array);
}

size_t		create_simple_lines_arrays(t_node *file, int *column_sizes,
		char ***lines_array)
{
	size_t	total_blocks;
	int		i;

	i = 0;
	total_blocks = 0;
	while (file)
	{
		total_blocks += ((t_file *)file->data)->info.st_blocks;
		lines_array[i] = create_simple_line_array(file->data, column_sizes);
		file = file->next;
		i++;
	}
	return (total_blocks);
}
