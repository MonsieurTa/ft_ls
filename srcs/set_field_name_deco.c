/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_field_symlink.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:11:02 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/13 15:10:57 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft/includes/libft.h"
#include "options.h"
#include "file.h"

static char		*get_link_target_with_deco(t_file *file)
{
	char		*result;
	ssize_t		ret;
	size_t		buf_size;

	buf_size = (file->stat.st_size == 0 ? PATH_MAX : file->stat.st_size);
	if ((result = (char *)malloc(5 + buf_size)) == NULL)
		return (NULL);
	ft_memcpy(result, " -> ", 4);
	if ((ret = readlink(file->path, result + 4, buf_size)) < 0)
	{
		free(result);
		return (NULL);
	}
	result[4 + ret] = '\0';
	return (result);
}

int				set_field_name_deco(t_opts *opts, t_file *file, char **field)
{
	if (opts == NULL || file == NULL || field == NULL)
	{
		if (field != NULL)
			*field = NULL;
		return (0);
	}
	if (get_opt(opts, LS_LONGF) == 1 && S_ISLNK(file->stat.st_mode))
		*field = get_link_target_with_deco(file);
	else if (get_opt(opts, LS_SLASHD) == 1 && S_ISDIR(file->stat.st_mode))
		*field = ft_strdup("/");
	else
		*field = ft_strdup("");
	return (*field == NULL ? 0 : ft_strlen(*field));
}
