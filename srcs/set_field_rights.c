/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_field_rights.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:17:25 by wta               #+#    #+#             */
/*   Updated: 2018/12/15 12:24:23 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"
#include "options.h"
#include "file.h"
#include "set_field.h"

static void	get_file_type(t_stat *stat, char *field)
{
	if (S_ISBLK(stat->st_mode))
		field[0] = 'b';
	else if (S_ISCHR(stat->st_mode))
		field[0] = 'c';
	else if (S_ISDIR(stat->st_mode))
		field[0] = 'd';
	else if (S_ISFIFO(stat->st_mode))
		field[0] = 'p';
	else if (S_ISLNK(stat->st_mode))
		field[0] = 'l';
	else if (S_ISREG(stat->st_mode))
		field[0] = '-';
	else if (S_ISSOCK(stat->st_mode))
		field[0] = 's';
	else
		field[0] = '?';
}

static void	get_rights(t_file *file, char *field)
{
	t_stat	*stat;

	stat = &file->stat;
	field[1] = (stat->st_mode & S_IRUSR) ? 'r' : '-';
	field[2] = (stat->st_mode & S_IWUSR) ? 'w' : '-';
	field[3] = (stat->st_mode & S_IXUSR) ? 'x' : '-';
	field[4] = (stat->st_mode & S_IRGRP) ? 'r' : '-';
	field[5] = (stat->st_mode & S_IWGRP) ? 'w' : '-';
	field[6] = (stat->st_mode & S_IXGRP) ? 'x' : '-';
	field[7] = (stat->st_mode & S_IROTH) ? 'r' : '-';
	field[8] = (stat->st_mode & S_IWOTH) ? 'w' : '-';
	field[9] = (stat->st_mode & S_IXOTH) ? 'x' : '-';
	if (stat->st_mode & S_ISUID)
		field[3] = (field[3] == 'x') ? 's' : 'S';
	if (stat->st_mode & S_ISGID)
		field[6] = (field[6] == 'x') ? 's' : 'S';
	if (stat->st_mode & S_ISVTX)
		field[9] = (field[9] == 'x') ? 't' : 'T';
	field[10] = (has_acl(file->path)) ? '+' : ' ';
	field[10] = (has_xattr(file->path)) ? '@' : field[10];
}

int			set_field_rights(t_opts *opts, t_file *file, char **field)
{
	if (opts == NULL || file == NULL || field == NULL)
	{
		if (field != NULL)
			*field = NULL;
		return (0);
	}
	if ((*field = ft_strnew(11)) != NULL)
	{
		get_file_type(&(file->stat), *field);
		get_rights(file, *field);
		return (11);
	}
	return (0);
}
