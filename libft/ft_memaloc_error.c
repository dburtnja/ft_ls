//
// Created by denys on 9/11/17.
//

#include <stdio.h>
#include "libft.h"

void    *ft_memalloc_error(size_t size)
{
    void    *ret;

    ret = ft_memalloc(size);
    if (ret == NULL)
    {
        perror(ft_strjoin("Fail to allocate memory with size: ", ft_itoa((int) size)));
        exit(-1);
    }
    return  ret;
}