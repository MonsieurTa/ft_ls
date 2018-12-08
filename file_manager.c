/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:48:29 by wta               #+#    #+#             */
/*   Updated: 2018/12/08 15:05:28 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"

t_lst_ls	*link_file(char *path)
{
	t_lst_ls	*lst;
	t_file		*file;
	DIR			*pdir;

	pdir = NULL;
/*
** TODO : Generer un message d'erreur depuis errno
*/
	if ((pdir = opendir(path)) == NULL)
		return (NULL);
	file = NULL;
	lst = NULL;
	while ((file = lst_newfile(pdir, path)) != NULL)
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

void	ls_rec(char *path, t_opts *opts)
{
	t_lst_ls	*h_lst;
	t_lst_ls	*lst;

	if ((lst = link_file(path)) == NULL)
		return ;
/*
** TODO : Afficher les fichiers et/ou dossier selon les options demandees
 */
	lst = lst_mergesort(lst, lst_size(lst));
	h_lst = lst;
	print_files(lst, opts);
	while ((lst = find_dir(lst)) != NULL)
	{
		ls_rec(lst->file->path, opts);
		lst = lst->next;
	}
	lst_rm(h_lst);
}
