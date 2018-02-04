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

static char	*create_format_string(size_t column_size, size_t file_name_size)
{
	char	*tabs;
	size_t	tabs_nbr;
	char	*result;

	tabs_nbr = (column_size - file_name_size + 3) / 4;
	tabs = ft_memalloc_error(tabs_nbr);
	ft_memset(tabs, '\t', tabs_nbr);
	tabs[tabs_nbr] = 0;
	result = ft_format("%%s%s", tabs);
	ft_strdel(&tabs);
	return result;
}

static void	print_lines(t_file ***array, size_t column_size)
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
			format = create_format_string(column_size, array[lines][columns]->name_len);
			ft_printf(format, array[lines][columns]->file_name);
			ft_strdel(&format);
			columns++;
		}
		lines++;
		if (array[lines])
			ft_putendl("");
	}
}

size_t		get_max_file_name(t_doubly_list *list)
{
	t_node	*node;
	size_t	max;

	node = list->head;
	max = ((t_file*)node->data)->name_len;
	while (node) {
		if (max < ((t_file *) node->data)->name_len)
			max = ((t_file *) node->data)->name_len;
		node = node->next;
	}
	return max;
}

void		simple_print(t_doubly_list *list, size_t width)
{
	size_t			lines_nbr;
	size_t			columns;
	t_file			***lines_to_print;
	size_t			max;

	max = get_max_file_name(list) + 4;
	columns = ((width + (max - 1)) / max);
	lines_nbr = ((list->size + (columns - 1)) / columns);
	lines_to_print = make_lines(list, lines_nbr, columns);
	print_lines(lines_to_print, max);
	if (lines_to_print[0][0])
		ft_putendl("");
}
