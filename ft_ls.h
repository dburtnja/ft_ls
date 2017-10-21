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

# include "libft/libft.h"

typedef struct      s_ls
{
    int             flags;
    char            *main_dir_name;
    t_doubly_list   *dirs;

}                   t_ls;

typedef struct      s_dir
{
    char            *dir_name;
}                   t_dir;

void                read_arguments(t_ls *ls, char **args, int args_size);
void                error(char *message, int status);
t_dir               *new_dir(char *name);


#endif //FT_LS_FT_LS_H
