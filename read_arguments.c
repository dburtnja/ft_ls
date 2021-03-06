/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arguments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:27:17 by dburtnja          #+#    #+#             */
/*   Updated: 2018/01/13 13:28:41 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft/libft.h"

static int	flag_selector(char f)
{
	if (f == 'l')
		return (FLAG_L);
	if (f == 'R')
		return (FLAG_RR);
	if (f == 'a')
		return (FLAG_A);
	if (f == 'r')
		return (FLAG_R);
	if (f == 't')
		return (FLAG_T);
	error(ft_strjoin("No such flag: ", &f), -2);
	return (0);
}

static int	read_flags_letters(char *flag)
{
	size_t	size;
	int		flags;

	flags = 0;
	size = ft_strlen(flag);
	while (size > 0)
	{
		size--;
		flags |= flag_selector(flag[size]);
	}
	return (flags);
}

static int	read_flags_word(char *flag)
{
	if (ft_strcmp(flag, "help") == 0)
		return (FLAG_HELP);
	error(ft_strjoin("No such flag: ", flag), -2);
	return (0);
}

void		read_arguments(t_ls *ls, char **args, int args_size)
{
	int		i;
	size_t	sizeof_dir_struct;

	i = 0;
	sizeof_dir_struct = sizeof(t_dir);
	ls->dirs = new_doubly_list(NULL, 0, 0, 0);
	while (args_size > i)
	{
		if (args[i][0] == '-' && args[i][1] == '-')
			ls->flags |= read_flags_word(args[i] + 2);
		else if (args[i][0] == '-')
			ls->flags |= read_flags_letters(args[i] + 1);
		else
			add_to_back(ls->dirs, new_node(new_dir(args[i], NULL),
						sizeof_dir_struct));
		i++;
	}
	if (ls->dirs->size == 0)
		add_to_front(ls->dirs, new_node(new_dir(".", NULL), sizeof_dir_struct));
}
