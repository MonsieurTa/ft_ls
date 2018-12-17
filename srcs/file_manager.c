/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:48:29 by wta               #+#    #+#             */
/*   Updated: 2018/12/17 17:01:17 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "fields_utils.h"
#include "error.h"

t_lst_ls	*link_file(char *path, t_opts *opts)
{
	t_lst_ls	*lst;
	t_lst_ls	*lst_back;
	t_file		*file;
	DIR			*pdir;

	init_fmt(opts);
	pdir = NULL;
	if ((pdir = opendir(path)) == NULL)
		return (NULL);
	file = lst_newfile(pdir, path, opts);
	if (file == NULL || (lst = lst_newnode(file)) == NULL)
	{
		closedir(pdir);
		return (NULL);
	}
	lst_back = lst;
	while ((file = lst_newfile(pdir, path, opts)) != NULL)
	{
		lst_back->next = lst_newnode(file);
		lst_back = lst_back->next;
	}
	closedir(pdir);
	return (lst);
}

t_lst_ls	*find_dir(t_lst_ls *lst)
{
	while (lst != NULL && (!S_ISDIR(lst->file->stat.st_mode)
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
