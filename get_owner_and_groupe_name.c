/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_owner_and_groupe_name.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 12:37:17 by dburtnja          #+#    #+#             */
/*   Updated: 2018/01/13 12:38:05 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <grp.h>
#include <pwd.h>
#include "ft_ls.h"

char	*get_group_name(gid_t id)
{
	struct group	*g;

	g = getgrgid(id);
	return (ft_strdup(g->gr_name));
}

char	*get_user_name(uid_t id)
{
	struct passwd	*p;

	p = getpwuid(id);
	return (ft_strdup(p->pw_name));
}
