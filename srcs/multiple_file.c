/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:42:20 by wta               #+#    #+#             */
/*   Updated: 2018/12/14 14:00:59 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "fields_utils.h"
#include "error.h"

char	*get_dirpath(char *filepath)
{
	int		len;

	if (filepath)
	{
		len = ft_strlen(filepath);
		while (len >= 0 && filepath[len] != '/')
			len--;
		if (len < 0)
			return (ft_strdup("."));
		else
			return (ft_strndup(filepath, len));
	}
	return (NULL);
}

char	*get_filename(char *filepath)
{
	int		len;

	if (filepath)
	{
		len = ft_strlen(filepath);
		while (len >= 0 && filepath[len] != '/')
			len--;
		if (len < 0)
			return (ft_strdup(filepath));
		else
			return (ft_strdup(&filepath[len + 1]));
	}
	return (NULL);
}

t_file	*single_file(char *filepath, t_stat *st_stat, t_opts *opts)
{
	t_file		*file;
	t_dirent	*tmp;
	char		*filename;
	char		*dirpath;
	DIR			*pdir;

	if ((filename = get_filename(filepath)) == NULL)
		return (NULL);
	if ((dirpath = get_dirpath(filepath)) == NULL)
	{
		free(filename);
		return (NULL);
	}
	if ((pdir = opendir(dirpath)) == NULL)
	{
		free(filename);
		free(dirpath);
		return (print_error(filename, st_stat));
	}
	while ((tmp = readdir(pdir)) != NULL)
		if (ft_strequ(tmp->d_name, filename) == 1)
			break;
	free(filename);
	free(dirpath);
	if (tmp != NULL && (file = ft_memalloc(sizeof(t_file))) != NULL)
	{
		if ((file->pdent = ft_memalloc(tmp->d_reclen)) != NULL)
		{
			ft_memcpy(file->pdent, tmp, tmp->d_reclen);
			if ((file->path = ft_strdup(filepath)) != NULL
					&& init_file_infs(file, opts) == 0)
			{
				closedir(pdir);
				if (S_ISDIR(file->stat.st_mode) == 0)
					return (file);
				else
					opts->has_dir = 1;
			}
			free(file->path);
		}
		if (get_opt(opts, LS_LONGF) == 1)
			delete_all_fields(file);
		else
			delete_minimum_fields(file);
		free(file->pdent);
		free(file);
	}
	return (NULL);
}

void	multiple_file(t_lst_info *lst, t_opts *opts, t_stat *st_stat, char *path)
{
	t_file	*file;

	if ((file = single_file(path, st_stat,opts)) != NULL)
		lst_append(&lst->head, &lst->tail, lst_newnode(file));
}
