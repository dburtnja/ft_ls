/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 10:43:19 by dburtnja          #+#    #+#             */
/*   Updated: 2018/01/13 10:46:29 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_FT_LS_H
# define FT_LS_FT_LS_H

# define FLAG_L 1
# define FLAG_RR 2
# define FLAG_A 4
# define FLAG_R 8
# define FLAG_T 16
# define FLAG_HELP 32

# define TYPE_DIR 1
# define TYPE_FILE 2

# include "libft/libft.h"
# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>

typedef struct		s_ls
{
	int				flags;
	t_doubly_list	*dirs;

}					t_ls;

typedef struct		s_dir
{
	char			*dir_with_path;
	t_doubly_list	*files;
	struct stat		info;
}					t_dir;

typedef struct		s_file
{
	char			*file_name;
	size_t			name_len;
	char			*file_with_path;
	struct stat		info;
}					t_file;

void				read_arguments(t_ls *ls, char **args, int args_size);
void				error(char *message, int status);
t_dir				*new_dir(char *name, char *path);
t_file				*new_file(char *name, char *path);
void				open_file(t_file *file);
void				open_directory(t_dir *directory, t_ls *ls);
void				print_ls(t_ls *ls);
void				recursive_search(t_ls *ls, t_dir *dir);
void				sort_before_print(t_ls *ls);
void				simple_print(t_doubly_list *list, size_t width);
int					by_name(t_node *first, t_node *second, int type);
void				list_print(t_dir *dir);
char				*get_group_name(gid_t id);
char				*get_user_name(uid_t id);
char				*read_chmod(struct stat info, char *file_name);
int					by_mod_time(t_node *first, t_node *second, int type);
t_file				***make_lines(t_doubly_list *list, size_t line_nbrs,
		size_t columns);
size_t				*get_column_sizes(t_file ***array, size_t columns);
size_t				create_simple_lines_arrays(t_node *file, int *column_sizes,
		char ***lines_array);

#endif
