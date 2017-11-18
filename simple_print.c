//
// Created by denys on 15.11.17.
//

#include <asm/ioctls.h>
#include <sys/ioctl.h>
#include "ft_ls.h"

static size_t   get_column_size(t_file ***array, size_t column_nbr)
{
    size_t  line;
    size_t  column_size;

    line = 0;
    column_size = 0;
    while (array[line])
    {
        if (array[line][column_nbr] && column_size < array[line][column_nbr]->name_len)
            column_size = (size_t) array[line][column_nbr]->name_len;
        line++;
    }
    return column_size;
}

static size_t   *get_column_sizes(t_file ***array, size_t columns)
{
    size_t  column_nbr;
    size_t  *column_sizes;

    column_nbr = 0;
    column_sizes = ft_memalloc_error(sizeof(size_t*) * (columns + 1));
    while (array[0][column_nbr])
    {
        column_sizes[column_nbr] = get_column_size(array, column_nbr);
        if (array[0][column_nbr + 1])
            column_sizes[column_nbr] += 2;
        column_nbr++;
    }
    return column_sizes;
}

static int  line_in_range(t_file ***array, size_t width, size_t columns, size_t **ret_column_sizes)
{
    size_t  *column_sizes;
    size_t  line_size;
    int     column_nbr;

    line_size = 0;
    column_sizes = get_column_sizes(array, columns);
    column_nbr = 0;
    while (column_sizes[column_nbr])
    {
        line_size += column_sizes[column_nbr];
        column_nbr++;
    }
    *ret_column_sizes = column_sizes;
    return line_size <= width;
}

static t_file   **make_line(t_file **files, size_t line_nbr, size_t line_nbrs, size_t columns, size_t files_size)
{
    size_t  j;
    t_file  **result;

    j = 0;
    result = ft_memalloc_error(sizeof(t_file*) * (columns + 1));
    while (line_nbr < files_size)
    {
        result[j] = files[line_nbr];
        line_nbr += line_nbrs;
        j++;
    }
    return result;
}

static t_file   ***make_lines(t_doubly_list* list, size_t line_nbrs, size_t columns)
{
    t_file  ***lines;
    size_t  i;
    t_file  **files;

    files = ft_double_list_to_array(list);
    lines = ft_memalloc_error(sizeof(t_file **) * (line_nbrs + 1));
    i = 0;
    while (i < line_nbrs)
    {
        lines[i] = make_line(files, i, line_nbrs, columns, list->size);
        i++;
    }
    ft_memdel((void **) &files);
    return lines;
}

static void print_lines(t_file ***array, size_t *column_sizes)
{
    int lines;
    int columns;
    char    *format;
    int     last;

    lines = 0;
    while (array[lines])
    {
        columns = 0;
        while (array[lines][columns])
        {
            last = (array[lines][columns + 1] == NULL);
            format = ft_format("%%-%ds", last ? 0 :column_sizes[columns]);
            ft_printf(format, array[lines][columns]->file_name);
            ft_strdel(&format);
            columns++;
        }
        ft_putendl("");
        lines++;
    }
}

void simple_print(t_doubly_list *list)
{
    struct winsize  w;
    size_t          lines_nbr;
    size_t          columns;
    size_t          *columns_sizes;
    t_file          ***lines_to_print;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w); //w.ws_col
    lines_nbr = 1;
    while (TRUE)
    {
        columns = ((list->size + lines_nbr) / lines_nbr);
        lines_to_print = make_lines(list, lines_nbr, columns);
        if (line_in_range(lines_to_print, w.ws_col, columns, &columns_sizes) || columns == 1)
            break;
        ft_memdel((void **) &columns_sizes);
        lines_nbr++;
    }
    print_lines(lines_to_print, columns_sizes);
}