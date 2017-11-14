//
// Created by denys on 01.09.17.
//

#ifndef FT_LS_FT_LS_H
# define FT_LS_FT_LS_H

# define    FLAG_l 1
# define    FLAG_R 2
# define    FLAG_a 4
# define    FLAG_r 8
# define    FLAG_t 16
# define    FLAG_help 32

# define    TYPE_DIR 1
# define    TYPE_FILE 2

# include "libft/libft.h"
# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>


typedef struct      s_ls
{
    int             flags;
    char            *main_dir_name;
    t_doubly_list   *dirs;

}                   t_ls;

typedef struct      s_dir
{
    char            *dir_name;
    char            *dir_with_path;
    t_doubly_list   *files;
}                   t_dir;

typedef struct      s_file
{
    char            *file_name;
    char            *file_with_path;
    struct stat     info;
}                   t_file;

void                read_arguments(t_ls *ls, char **args, int args_size);
void                error(char *message, int status);
t_dir               *new_dir(char *name, char *path);
t_file              *new_file(char *name, char *path);
void                open_file(t_ls *ls, t_file *file);
int                 open_directory(t_dir *directory, t_ls *ls);
void                print_ls(t_ls *ls);
void                recursive_search(t_ls *ls, t_dir *dir);
void                sort_before_print(t_ls *ls);


#endif //FT_LS_FT_LS_H
