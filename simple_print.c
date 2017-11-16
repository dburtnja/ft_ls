//
// Created by denys on 15.11.17.
//

#include <asm/ioctls.h>
#include <sys/ioctl.h>
#include "ft_ls.h"

static int  line_in_range(char ***array, int width)
{

}

static t_node   *copy_from_list_to_array(t_node *head, t_file **array, size_t columns)
{
    size_t  i;

    i = 0;
    while (head && i < columns)
    {
        array[i] = head->data;
        head = head->next;
        i++;
    }
    return head;
}

static t_file   ***make_lines(t_doubly_list* list, int lines_nbr)
{
    t_file  ***lines;
    int     i;
    size_t  columns;
    t_node  *node;

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
    return lines;
}

static void print_lines(t_file ***array)
{
    int lines;
    int columns;

    char    *str;

    lines = 0;

    while (array[lines])
    {
        columns = 0;
        while (array[lines][columns])
        {
            ft_printf("%p\n", array[lines][columns]);
//            str = array[lines][columns]->file_name;
//            ft_putendl(str);
//            ft_putendl(ft_format("%s", str));
//            ft_putnbr(columns);
            columns++;
        }
        ft_putnbr(columns);
        ft_putendl("");
        lines++;
    }
//    for (int j = 0; j < 32; j++)
//        ft_printf("%s", array[0][j]->file_name);
}

void simple_print(t_doubly_list *list)
{
    struct winsize  w;
    int             lines_nbr;
    t_file          ***lines_to_print;




//    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w); //w.ws_col

    lines_nbr = 1;
    while (TRUE)
    {
        lines_to_print = make_lines(list, lines_nbr);


//        if (line_in_range(lines_to_print, 50) || ft_strlen((char*)(*lines_to_print)) == 1)
        break;
    }
    print_lines(lines_to_print);
}