/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_field_symlink.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:11:02 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/13 14:19:37 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft/includes/libft.h"
#include "options.h"
#include "file.h"

int		set_field_symlink(t_opts *opts, t_file *file, char **field)
{
	ssize_t		ret;
	size_t		buf_size;

	if (opts == NULL || file == NULL || field == NULL)
	{
		if (field != NULL)
			*field = NULL;
		return (0);
	}
	if (S_ISLNK(file->stat.st_mode))
	{
		buf_size = (file->stat.st_size == 0 ? PATH_MAX : file->stat.st_size);
		if ((*field = (char *)malloc(5 + buf_size)) == NULL)
			return (0);
		ft_memcpy(*field, " -> ", 4);
		if ((ret = readlink(file->path, (*field) + 4, buf_size)) < 0)
		{
			ft_memdel((void**)field);
			return (0);
		}
		(*field)[4 + ret] = '\0';
	}
	else
		*field = ft_strdup("");
	return (*field == NULL ? 0 : ft_strlen(*field));
}
