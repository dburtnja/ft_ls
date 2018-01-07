#include "ft_ls.h"

static char my_to_lower(char c)
{
	return (char) ft_tolower(c);
}

static int	my_strcmp(const unsigned char *s1, const unsigned char *s2)
{
	size_t  first;
	size_t  second;

	first = 0;
	second = 0;
	while (s1[first] && s2[second])
	{
		while (s1[first] && ft_isascii(s1[first]) && !ft_isalnum(s1[first]))
			first++;
		while (s2[second] && ft_isascii(s2[second]) && !ft_isalnum(s2[second]))
			second++;
		if (s1[first] != s2[second] || !s1[first] || !s2[second])
			break;
		first++;
		second++;
	}
	return s1[first] - s2[second];
}

int			by_name(t_node *first, t_node *second, int type)
{
	char    *first_name;
	char    *second_name;

	if (type == TYPE_DIR)
	{
		first_name = ft_strmap(((t_dir*)first->data)->dir_with_path, &my_to_lower);
		second_name = ft_strmap(((t_dir*)second->data)->dir_with_path, &my_to_lower);
	}
	else if (type == TYPE_FILE)
	{
		first_name = ft_strmap(((t_file *) first->data)->file_name, &my_to_lower);
		second_name = ft_strmap(((t_file *) second->data)->file_name, &my_to_lower);
	}
	if (type == TYPE_FILE || type == TYPE_DIR)
		return my_strcmp((unsigned char *) first_name, (unsigned char *) second_name);
	else
		return (0);
}

int			by_mod_time(t_node *first, t_node *second, int type)
{
	long	first_time;
	long	second_time;

	if (type == TYPE_DIR)
	{
		first_time = ((t_dir*)first->data)->info.st_mtimespec.tv_sec;
		second_time =((t_dir*)second->data)->info.st_mtimespec.tv_sec;
	}
	else if (type == TYPE_FILE)
	{
		first_time = ((t_file *) first->data)->info.st_mtimespec.tv_sec;
		second_time =((t_file *) second->data)->info.st_mtimespec.tv_sec;
	}
	if (type == TYPE_FILE || type == TYPE_DIR)
		return first_time == second_time ? by_name(first, second, type) :
			   first_time < second_time;
	else
		return (0);
}
