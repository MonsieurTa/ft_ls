/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:42:20 by wta               #+#    #+#             */
/*   Updated: 2018/12/18 12:25:08 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "fields_utils.h"
#include "error.h"

static char		*get_filename_from_path(char *filepath)
{
	int		len;

	if (filepath)
	{
		len = ft_strlen(filepath) - 1;
		while (len >= 0 && filepath[len] == '/')
			len--;
		while (len >= 0 && filepath[len] != '/')
			len--;
		if (len < 0)
			return (ft_strdup(filepath));
		else
			return (ft_strdup(&filepath[len + 1]));
	}
	return (NULL);
}

static t_file	*ret_dir(t_file *file, t_opts *opts)
{
	if (S_ISDIR(file->stat.st_mode) && get_opt(opts, LS_DIRASF) == 0)
		return (NULL);
	else
		return (file);
}

static t_file	*setup_file(t_file *file, t_opts *opts)
{
	if (init_file_infs(file, opts) == 0)
	{
		if ((file = ret_dir(file, opts)) != NULL)
			return (file);
		else
		{
			if (get_opt(opts, LS_LONGF) == 1)
				delete_all_fields(file);
			else
				delete_minimum_fields(file);
		}
	}
	return (NULL);
}

static t_file	*single_file(char *filepath, t_opts *opts)
{
	t_file		*file;

	if ((file = ft_memalloc(sizeof(t_file))) != NULL)
	{
		if ((file->name = get_filename_from_path(filepath)) != NULL)
		{
			if ((file->path = ft_strdup(filepath)) != NULL)
				if ((file = setup_file(file, opts)) != NULL)
					return (file);
			free(file->path);
		}
		free(file->name);
		free(file);
	}
	return (NULL);
}

void			multiple_file(t_lst_info *lst, t_opts *opts, char *path)
{
	t_file	*file;

	if ((file = single_file(path, opts)) != NULL)
	{
		opts->has_file = 1;
		lst_append(&lst->head, &lst->tail, lst_newnode(file));
	}
}
