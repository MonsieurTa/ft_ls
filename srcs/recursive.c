/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 05:51:37 by wta               #+#    #+#             */
/*   Updated: 2018/12/15 11:15:48 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "print.h"
#include "set_field.h"

void	ls_rec(char *path, t_opts *opts)
{
	t_stat		st_stat;
	t_lst_ls	*h_lst;
	t_lst_ls	*lst;

	if (lstat(path, &st_stat) == -1)
		return ;
	ft_printf("\n%s:\n", path);
	if ((lst = link_file(path, &st_stat, opts)) == NULL)
		return ;
	if (opts->cmp_fun != NULL)
		lst = lst_mergesort(lst, opts->cmp_fun);
	h_lst = lst;
	print_files(lst, opts);
	while ((lst = find_dir(lst)) != NULL)
	{
		if (get_opt(opts, LS_ALL) == 1)
		{
			if (is_curr_or_parent(lst->file->pdent) == 0)
				ls_rec(lst->file->path, opts);
		}
		else if (is_hidden(lst->file) == 0)
			ls_rec(lst->file->path, opts);
		lst = lst->next;
	}
	lst_rm(h_lst, opts);
}
