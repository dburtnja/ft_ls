//
// Created by denys on 10/22/17.
//

#include "ft_printf.h"

char	*ft_format(char *str, ...)
{
    t_arg	*head;
    va_list arg_ptr;

    if (!str)
        return (NULL);
    va_start(arg_ptr, str);
    head = read_str(str, arg_ptr);
    collect_str(head, &str);
    va_end(arg_ptr);
    return (str);
}