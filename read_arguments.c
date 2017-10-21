//
// Created by denys on 9/10/17.
//

#include "ft_ls.h"
#include "libft/libft.h"

static int  flag_selector(char f)
{
    if (f == 'l')
        return FLAG_l;
    if (f == 'R')
        return FLAG_R;
    if (f == 'a')
        return FLAG_a;
    if (f == 'r')
        return FLAG_r;
    if (f == 't')
        return FLAG_t;
    error(ft_strjoin("No such flag: ", &f), -2); //might be an error in &f
}

static int  read_flags_letters(char *flag)
{
    size_t  size;
    int     flags;

    flags = 0;
    size = ft_strlen(flag);
    while (size > 0)
    {
        size--;
        flags |= flag_selector(flag[size]);
    }
    return flags;
}

static int  read_flags_word(char *flag)
{
    if (ft_strcmp(flag, "help") == 0)
        return FLAG_help;
    error(ft_strjoin("No such flag: ", flag), -2);
}

static char *add_root(char *root, char *dir)
{
    char    *ret;

    root = ft_strjoin(root, "/");
    ret = ft_strjoin(root, dir);
    ft_memdel((void **) &root);
    return ret;
}

void        read_arguments(t_ls *ls, char **args, int args_size)
{
    int     i;
    size_t  sizeof_dir_struct;

    i = 0;
    sizeof_dir_struct = sizeof(t_dir);
    ls->dirs = new_doubly_list(NULL);
    while (args_size > i)
    {
        if (args[i][0] == '-' && args[i][1] == '-')
            ls->flags |= read_flags_word(args[i] + 2);
        else if (args[i][0] == '-')
            ls->flags |= read_flags_letters(args[i] + 1);
        else
            add_to_back(ls->dirs, new_node(new_dir(args[i]), sizeof_dir_struct));
        i++;
    }
    if (ls->dirs->size == 0)
        add_to_front(ls->dirs, new_node(new_dir(ls->main_dir_name), sizeof_dir_struct));
}
