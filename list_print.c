//
// Created by denys on 25.11.17.
//

#include "ft_ls.h"

static char	*create_format_string(int *array)
{
	char	*format;

	format = ft_format(
			"%%-%ds %%-%ds %%-%ds %%-%ds %%-%ds %%.12s %%-s\n",
			array[0],
			array[1],
			array[2],
			array[3],
			array[4]
	);
	return format;
}

static void put_columns(char *format, char **line)
{
	ft_printf(
			format,
			line[0],
			line[1],
			line[2],
			line[3],
			line[4],
			&line[5][4],
			line[6]
	);
}

static void simple_list_print(t_doubly_list *files)
{
	int		*column_sizes;
	char	***lines_array;
	size_t	block_size;
	char	*format;
	int		i;

	i = 0;
	column_sizes = ft_memalloc_error(sizeof(int) * 7);
	lines_array = ft_memalloc_error(sizeof(char **) * (files->size + 1));
	block_size = create_simple_lines_arrays(files->head, column_sizes,
											lines_array);
	ft_printf("total %zd\n", block_size / 2);
	format = create_format_string(column_sizes);
	while (lines_array[i])
	{
		put_columns(format, lines_array[i]);
		i++;
	}
}

void list_print(t_dir *dir)
{
	simple_list_print(dir->files);
}