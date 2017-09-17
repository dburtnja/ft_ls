//
// Created by denys on 01.09.17.
//

#ifndef FT_LS_FT_LS_H
# define FT_LS_FT_LS_H

# define    FLAG_l = 1;
# define    FLAG_R = 2;
# define    FLAG_a = 4;
# define    FLAG_r = 8;
# define    FLAG_t = 16;

typedef struct      s_ls
{
    char            *start_path;
    int             flags;
    char            **dirs;
}                   t_ls;

void                read_arguments(t_ls *ls, char **args, int args_size);
void                error(char *message, int status);


#endif //FT_LS_FT_LS_H
