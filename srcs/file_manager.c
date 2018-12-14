/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:48:29 by wta               #+#    #+#             */
/*   Updated: 2018/12/14 10:41:37 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "fields_utils.h"

//TODO ameliorer la gestion d'erreur
t_lst_ls	*link_file(char *path, t_opts *opts)
{
	t_lst_ls	*lst;
	t_lst_ls	*lst_back;
	t_file		*file;
	DIR			*pdir;

	opts->fmt.hard_link_max_s = 0;
	opts->fmt.user_max_s = 0;
	opts->fmt.group_max_s = 0;
	opts->fmt.size_max_s = 0;
	opts->fmt.name_with_deco_max_s = 0;
	opts->fmt.lst_size = 0;
	pdir = NULL;
	if (access(path, X_OK) != 0 || (pdir = opendir(path)) == NULL)
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

int			init_file_infs(t_file *file, t_opts *opts)
{
	int		fun_ret;

	fun_ret = lstat(file->path, &(file->stat));
	if (fun_ret == 0)
	{
		if (get_opt(opts, LS_LONGF) == 1)
			fun_ret = init_all_fields_and_fmt(opts, file);
		else
			fun_ret = init_minimum_fields_and_fmt(opts, file);
		if (fun_ret == 0)
			return (0);
	}
	return (-1);
}
