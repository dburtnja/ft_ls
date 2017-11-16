//
// Created by denys on 15.11.17.
//

#include <asm/ioctls.h>
#include <sys/ioctl.h>
#include "ft_ls.h"

static int  line_in_range(char ***array, int width)
{

}

static t_node   *copy_from_list_to_array(t_node *head, void **array, size_t columns)
{
    size_t  i;

    i = 0;
    while (head || i < columns)
    {
        array[i] = head;
        head = head->next;
        i++;
    }
    return head;
}

static void     ***make_lines(t_doubly_list* list, int lines_nbr)
{
    void    ***lines;
    int     i;
    size_t  columns;
    void    *node;

    lines = ft_memalloc((size_t) lines_nbr + 1);
    columns = ((list->size + lines_nbr) / lines_nbr);
    node = list->head;
    i = 0;
    while (i < lines_nbr)
    {
        lines[i] = ft_memalloc(columns + 1);
        node = copy_from_list_to_array(node, lines[i], columns);
        i++;
    }
}

static void print_lines(void ***array)
{
    int lines;
    int columns;

    lines = 0;
    ft_putendl("PRINTING ARRAY");
    while (array[lines])
    {
        columns = 0;
        while (array[lines][columns])
        {
            ft_printf("%s  ", ((t_file *)array[lines][columns])->file_name);
            columns++;
        }
        ft_putendl("");
        lines++;
    }
}

void simple_print(t_doubly_list *list)
{
    struct winsize  w;
    int             lines_nbr;
    void            ***lines_to_print;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w); //w.ws_col
    lines_nbr = 1;
    while (TRUE)
    {
        lines_to_print = make_lines(list, lines_nbr);
//        if (line_in_range(lines_to_print, 50) || ft_strlen((char*)(*lines_to_print)) == 1)
        break;
    }
    print_lines(lines_to_print);
}