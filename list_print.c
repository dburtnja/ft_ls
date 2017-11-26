//
// Created by denys on 25.11.17.
//

#include <time.h>
#include "ft_ls.h"

static void update_column_sizes(int *column_sizes, char **line_array)
{
	int	i;
	int size;

	i = 0;
	while (line_array[i])
	{
		size = (int) ft_strlen(line_array[i]);
		column_sizes[i] = column_sizes[i] < size ? size : column_sizes[i];
		i++;
	}
}

static char	**create_simple_line_array(t_file *file, int *column_sizes)
{
	char	**line_array;

	line_array = ft_memalloc_error(sizeof(char *) * 8);
	line_array[0] = read_chmod(file->info);
	line_array[1] = ft_itoa((int) file->info.st_nlink);
	line_array[2] = get_group_name(file->info.st_gid);
	line_array[3] = get_user_name(file->info.st_uid);
	line_array[4] = ft_itoa((int) file->info.st_size);
	line_array[5] = ft_strdup(ctime(&(file->info.st_mtim.tv_sec)));
	line_array[6] = file->file_name;
	update_column_sizes(column_sizes, line_array);
	return line_array;
}

static size_t	create_simple_lines_arrays(t_node *file, int *column_sizes, char
***lines_array)
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
	return total_blocks;
}

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