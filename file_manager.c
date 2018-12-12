/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:48:29 by wta               #+#    #+#             */
/*   Updated: 2018/12/11 16:31:14 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"

t_lst_ls	*link_file(char *path, t_opts *opts)
{
	t_lst_ls	*lst;
	t_file		*file;
	DIR			*pdir;

	pdir = NULL;
	if (access(path, X_OK) != 0 || (pdir = opendir(path)) == NULL)
		return (NULL);
	file = NULL;
	lst = NULL;
	while ((file = lst_newfile(pdir, path, opts)) != NULL)
		lst_append(&lst, lst_newnode(file));
	closedir(pdir);
	return (lst);
}

t_lst_ls	*find_dir(t_lst_ls *lst)
{
	while (lst != NULL && (lst->file->pdent->d_type != DT_DIR
		|| ft_strcmp(lst->file->pdent->d_name, ".") == 0
		|| ft_strcmp(lst->file->pdent->d_name, "..") == 0))
		lst = lst->next;
	return (lst);
}

t_lst_ls	*find_file(t_lst_ls *lst)
{
	while (lst != NULL
		&& (ft_strcmp(lst->file->pdent->d_name, ".") == 0
		|| ft_strcmp(lst->file->pdent->d_name, "..") == 0))
		lst = lst->next;
	return (lst);
}

t_file		*is_symlink(t_file *file)
{
	if (file->pdent->d_type == DT_LNK)
	{
		if ((lstat(file->path, &(file->stat)) == 0))
			return (file);
	}
	else
	{
		if ((stat(file->path, &(file->stat)) == 0))
			return (file);
	}
	return (NULL);
}
