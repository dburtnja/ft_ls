//
// Created by denys on 19.11.17.
//

#include "ft_ls.h"

static int	my_strcmp(const unsigned char *s1, const unsigned char *s2)
{
	size_t  first;
	size_t  second;

	first = 0;
	second = 0;
	while (s1[first] == s2[second] && s1[first] != '\0' && s2[second] != '\0')
	{
		first++;
		second++;
		while (s1[first] == '.')
			first++;
		while (s2[second] == '.')
			second++;
	}
	if (s1[first] - s2[second] == 0)
		return (int) (first - second);
	return s1[first] - s2[second];
}

int  by_name(t_node *first, t_node *second, int type)
{
	char    *first_name;
	char    *second_name;

	if (type == TYPE_DIR)
	{
		first_name = ft_strmap(((t_dir*)first->data)->dir_with_path, &ft_tolower);
		second_name = ft_strmap(((t_dir*)second->data)->dir_with_path, &ft_tolower);
	}
	else if (type == TYPE_FILE)
	{
		first_name = ft_strmap(((t_file *) first->data)->file_name, &ft_tolower);
		second_name = ft_strmap(((t_file *) second->data)->file_name, &ft_tolower);
	}
	if (type == TYPE_FILE || type == TYPE_DIR)
		return my_strcmp(first_name, second_name);
	else
		return (0);
}