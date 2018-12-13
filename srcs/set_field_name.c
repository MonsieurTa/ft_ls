/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_field_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 09:05:00 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/13 12:43:56 by fwerner          ###   ########.fr       */
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

int				set_field_name(t_opts *opts, t_file *file, char **field)
{
	char	*tmp;

	if (opts == NULL || file == NULL || field == NULL)
	{
		if (field != NULL)
			*field = NULL;
		return (0);
	}
	if (get_opt(opts, LS_LONGF) == 1 && S_ISLNK(file->stat.st_mode))
	{
		tmp = get_link_target_with_deco(file);
		*field = ft_strjoin(file->pdent->d_name, tmp);
		free(tmp);
	}
	else if (get_opt(opts, LS_SLASHD) == 1 && S_ISDIR(file->stat.st_mode))
	{
		*field = ft_strjoin(file->pdent->d_name, "/");
	}
	else
	{
		*field = ft_strdup(file->pdent->d_name);
	}
	return (*field == NULL ? 0 : ft_strlen(*field));
}
