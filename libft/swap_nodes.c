//
// Created by denys on 19.11.17.
//

#include "libft.h"

int		swap_nodes(t_node *first, t_node *second)
{
	void    *buf_data;
	size_t  buf_size;

	if (!first || !second)
		return FALSE;
	buf_data = first->data;
	buf_size = first->data_size;
	first->data = second->data;
	first->data_size = second->data_size;
	second->data = buf_data;
	second->data_size = buf_size;
	return TRUE;
}