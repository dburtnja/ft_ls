//
// Created by denys on 10/22/17.
//

#include "ft_printf.h"

char	*ft_format(char *input_str, ...)
{
    t_arg	*head;
    va_list arg_ptr;
    char    *str;

    if (!input_str)
        return (NULL);
    va_start(arg_ptr, input_str);
    head = read_str(input_str, arg_ptr);
    collect_str(head, &str);
    va_end(arg_ptr);
    return (str);
}