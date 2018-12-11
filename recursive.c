/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 05:51:37 by wta               #+#    #+#             */
/*   Updated: 2018/12/11 15:19:11 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "print.h"
#include "set_field.h"

void	ls_rec(char *path, char *currdir, t_opts *opts)
{
	t_lst_ls	*h_lst;
	t_lst_ls	*lst;
	char		*field;

	if (ft_strcmp(path, currdir) != 0)
		ft_printf("\n%s:\n", path);
	if ((lst = link_file(path, opts)) == NULL)
		return ;
/*
** TODO : Afficher les fichiers et/ou dossier selon les options demandees
*/
	if (opts->cmp_fun != NULL)
		lst = lst_mergesort(lst, lst_size(lst), opts->cmp_fun);
	h_lst = lst;
	print_files(lst, opts);
	while ((lst = find_dir(lst)) != NULL)
	{
		if (get_opt(opts, LS_ALL) == 1)
		{
			if (is_curr_or_parent(lst->file->pdent) == 0)
				ls_rec(lst->file->path, currdir, opts);
		}
		else
			if (is_hidden(lst->file) == 0)
				ls_rec(lst->file->path, currdir, opts);
		lst = lst->next;
	}
	lst_rm(h_lst);
}
