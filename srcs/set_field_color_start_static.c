/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_field_color_start_static.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 12:48:00 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/13 13:05:48 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "options.h"
#include "file.h"
#include "set_field.h"

int		set_field_color_start_static(t_opts *opts, t_file *file, char **field)
{
	if (opts == NULL || file == NULL || field == NULL)
	{
		if (field != NULL)
			*field = NULL;
		return (0);
	}
	if (get_opt(opts, LS_COLOR) == 1)
	{
		if (S_ISDIR(file->stat.st_mode))
			*field = "\033[34m";
		else if (S_ISLNK(file->stat.st_mode))
			*field = "\033[35m";
		else if (S_ISSOCK(file->stat.st_mode))
			*field = "\033[32m";
		else if (S_ISFIFO(file->stat.st_mode))
			*field = "\033[33m";
		else if (file->stat.st_mode & S_IXUSR)
			*field = "\033[31m";
		else
			*field = "";
	}
	else
	{
		*field = "";
	}
	return (0);
}
