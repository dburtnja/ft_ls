//
// Created by denys on 25.11.17.
//

#include "ft_ls.h"

static char	get_type(__mode_t st_mode)
{
	if (S_ISREG(st_mode))
		return '-';
	else if (S_ISDIR(st_mode))
		return 'd';
	else if (S_ISLNK(st_mode))
		return  'l';
	else if (S_ISBLK(st_mode))
		return 'b';
	else if (S_ISCHR(st_mode))
		return 'c';
	else if (S_ISFIFO(st_mode))
		return 'p';
	return ' ';
}

static void	put_chmod(__mode_t st_mode, char *chmod)
{
	if (st_mode & S_IRUSR || st_mode & S_IRGRP || st_mode & S_IROTH)
		chmod[0] = 'r';
	else
		chmod[0] = '-';
	if (st_mode & S_IWUSR || st_mode & S_IWGRP || st_mode & S_IWOTH)
		chmod[1] = 'w';
	else
		chmod[1] = '-';
	if (st_mode & S_IXUSR || st_mode & S_IXGRP || st_mode & S_IXOTH)
		chmod[2] = 'x';
	else
		chmod[2] = '-';
}

char		*read_chmod(struct stat info)
{
	char	*chmod;

	chmod = ft_strnew(11);
	chmod[0] = get_type(info.st_mode);
	put_chmod(info.st_mode & S_IRWXU, &(chmod[1]));
	put_chmod(info.st_mode & S_IRWXG, &(chmod[4]));
	put_chmod(info.st_mode & S_IRWXO, &(chmod[7]));
	return chmod;
}