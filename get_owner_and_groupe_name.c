//
// Created by denys on 26.11.17.
//

#include <grp.h>
#include <pwd.h>
#include "ft_ls.h"

char	*get_group_name(gid_t id)
{
	struct group	*g;

	g = getgrgid(id);
	return ft_strdup(g->gr_name);
}

char	*get_user_name(uid_t id)
{
	struct passwd	*p;

	p = getpwuid(id);
	return ft_strdup(p->pw_name);
}