/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:42:20 by wta               #+#    #+#             */
/*   Updated: 2018/12/17 13:08:52 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "fields_utils.h"
#include "error.h"

static t_dirent	*get_dent(char *filepath, t_stat *st_stat)
{
	t_dirent	*tmp;
	char		*filename;
	char		*dirpath;
	DIR			*pdir;

	if ((filename = get_filename(filepath)) == NULL)
		return (NULL);
	if ((dirpath = get_dirpath(filepath, filename)) == NULL)
		return (NULL);
	if ((pdir = opendir(dirpath)) == NULL)
	{
		free(filename);
		free(dirpath);
		return (print_error(filename, 0, st_stat));
	}
	while ((tmp = readdir(pdir)) != NULL)
		if (ft_strequ(tmp->d_name, filename) == 1)
			break ;
	free(filename);
	free(dirpath);
	closedir(pdir);
	return (tmp);
}

static t_file	*ret_dir(t_file *file, t_opts *opts)
{
	if (S_ISDIR(file->stat.st_mode) == 0)
		return (file);
	else
		opts->has_dir = 1;
	return (NULL);
}

static t_file	*single_file(char *filepath, t_stat *st_stat, t_opts *opts)
{
	t_dirent	*tmp;
	t_file		*file;

	if ((tmp = get_dent(filepath, st_stat)) == NULL)
		return (NULL);
	if (tmp != NULL && (file = ft_memalloc(sizeof(t_file))) != NULL)
	{
		if ((file->pdent = ft_memalloc(tmp->d_reclen)) != NULL)
		{
			ft_memcpy(file->pdent, tmp, tmp->d_reclen);
			if ((file->path = ft_strdup(filepath)) != NULL)
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
			}
			free(file->path);
		}
		free(file->pdent);
		free(file);
	}
	return (NULL);
}

void			multiple_file(t_lst_info *lst,
							t_opts *opts, t_stat *st_stat, char *path)
{
	t_file	*file;

	if ((file = single_file(path, st_stat, opts)) != NULL)
		lst_append(&lst->head, &lst->tail, lst_newnode(file));
}
