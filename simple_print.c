/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:04:49 by dburtnja          #+#    #+#             */
/*   Updated: 2018/01/13 13:07:10 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	*get_format_string(t_file **line, size_t *column_sizes, int columns)
{
	size_t	size;

	size = line[columns + 1] == NULL ? 0 : column_sizes[columns];
	if (((unsigned char*)line[columns]->file_name)[0] > 127)
		size = (size - line[columns]->name_len) + line[columns]->name_len * 2;
	return (ft_format("%%-%ds", size));
}

static void	print_lines(t_file ***array, size_t *column_sizes)
{
	int		lines;
	int		columns;
	char	*format;

	lines = 0;
	while (array[lines])
	{
		columns = 0;
		while (array[lines][columns])
		{
			format = get_format_string(array[lines], column_sizes, columns);
			ft_printf(format, array[lines][columns]->file_name);
			ft_strdel(&format);
			columns++;
		}
		lines++;
		if (array[lines])
			ft_putendl("");
	}
}

static int	line_in_range(t_file ***array, size_t width, size_t columns,
		size_t **ret_column_sizes)
{
	size_t	*column_sizes;
	size_t	line_size;
	int		column_nbr;

	line_size = 0;
	column_sizes = get_column_sizes(array, columns);
	column_nbr = 0;
	while (column_sizes[column_nbr])
	{
		line_size += column_sizes[column_nbr];
		column_nbr++;
	}
	*ret_column_sizes = column_sizes;
	return (line_size <= width);
}

void		simple_print(t_doubly_list *list, size_t width)
{
	size_t			lines_nbr;
	size_t			columns;
	size_t			*columns_sizes;
	t_file			***lines_to_print;

	lines_nbr = 1;
	while (TRUE)
	{
		columns = ((list->size + (lines_nbr - 1)) / lines_nbr);
		lines_to_print = make_lines(list, lines_nbr, columns);
		if (line_in_range(lines_to_print, width, columns, &columns_sizes) ||
				columns == 1)
			break ;
		ft_memdel((void **)&columns_sizes);
		lines_nbr++;
	}
	print_lines(lines_to_print, columns_sizes);
	if (lines_to_print[0][0])
		ft_putendl("");
}
