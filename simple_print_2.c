/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_print_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:08:46 by dburtnja          #+#    #+#             */
/*   Updated: 2018/01/13 13:12:25 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static size_t	get_column_size(t_file ***array, size_t column_nbr)
{
	size_t	line;
	size_t	column_size;

	line = 0;
	column_size = 0;
	while (array[line])
	{
		if (array[line][column_nbr] &&
				column_size < array[line][column_nbr]->name_len)
			column_size = (size_t)array[line][column_nbr]->name_len;
		line++;
	}
	return (column_size);
}

size_t			*get_column_sizes(t_file ***array, size_t columns)
{
	size_t	column_nbr;
	size_t	*column_sizes;

	column_nbr = 0;
	column_sizes = ft_memalloc_error(sizeof(size_t*) * (columns + 1));
	while (array[0][column_nbr])
	{
		column_sizes[column_nbr] = get_column_size(array, column_nbr);
		if (array[0][column_nbr + 1])
			column_sizes[column_nbr] += 2;
		column_nbr++;
	}
	return (column_sizes);
}

static t_file	**make_line(t_file **files, size_t line_nbr, size_t line_nbrs,
		size_t columns, size_t files_size)
{
	size_t	j;
	t_file	**result;

	j = 0;
	result = ft_memalloc_error(sizeof(t_file*) * (columns + 1));
	while (line_nbr < files_size)
	{
		result[j] = files[line_nbr];
		line_nbr += line_nbrs;
		j++;
	}
	return (result);
}

t_file			***make_lines(t_doubly_list* list, size_t line_nbrs, size_t columns)
{
	t_file	***lines;
	size_t	i;
	t_file	**files;

	files = ft_double_list_to_array(list);
	lines = ft_memalloc_error(sizeof(t_file **) * (line_nbrs + 1));
	i = 0;
	while (i < line_nbrs)
	{
		lines[i] = make_line(files, i, line_nbrs, columns, list->size);
		i++;
	}
	ft_memdel((void **) &files);
	return (lines);
}
