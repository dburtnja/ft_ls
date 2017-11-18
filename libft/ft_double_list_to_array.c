//
// Created by denys on 17.11.17.
//

#include "libft.h"

void    *ft_double_list_to_array(t_doubly_list *list)
{
    void    **data_array;
    t_node  *node;
    size_t  i;

    data_array = ft_memalloc(sizeof(void *) * list->size + 1);
    if (!data_array)
        return NULL;
    i = 0;
    node = list->head;
    while (node)
    {
        if (i > list->size)
        {
            ft_memdel((void*)(&data_array));
            return NULL;
        }
        data_array[i] = node->data;
        node = node->next;
        i++;
    }
    return data_array;
}