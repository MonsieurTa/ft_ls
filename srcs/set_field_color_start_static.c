/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_field_color_start_static.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 12:48:00 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/15 09:16:38 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "options.h"
#include "file.h"
#include "set_field.h"

static int	set_field_color_dir(t_file *file, char **field)
{
	if (S_ISDIR(file->stat.st_mode))
	{
		if (file->stat.st_mode & S_IWOTH && file->stat.st_mode & S_ISVTX)
			*field = "\033[30;42m";
		else if (file->stat.st_mode & S_IWOTH)
			*field = "\033[30;43m";
		else
			*field = "\033[34m";
		return (1);
	}
	return (0);
}

static int	set_field_color_exec(t_file *file, char **field)
{
	if (file->stat.st_mode & S_IXUSR)
	{
		if (file->stat.st_mode & S_ISUID)
			*field = "\033[30;41m";
		else if (file->stat.st_mode & S_ISGID)
			*field = "\033[30;46m";
		else
			*field = "\033[31m";
		return (1);
	}
	return (0);
}

int			set_field_color_start_static(t_opts *opts, t_file *file,
		char **field)
{
	if (opts == NULL || file == NULL || field == NULL)
	{
		if (field != NULL)
			*field = NULL;
		return (0);
	}
	*field = "";
	if (get_opt(opts, LS_COLOR) == 1)
	{
		if (set_field_color_dir(file, field) == 1)
			return (0);
		else if (S_ISLNK(file->stat.st_mode))
			*field = "\033[35m";
		else if (S_ISSOCK(file->stat.st_mode))
			*field = "\033[32m";
		else if (S_ISFIFO(file->stat.st_mode))
			*field = "\033[33m";
		else if (S_ISBLK(file->stat.st_mode))
			*field = "\033[34;46m";
		else if (S_ISCHR(file->stat.st_mode))
			*field = "\033[34;43m";
		else if (set_field_color_exec(file, field) == 1)
			return (0);
	}
	return (0);
}
