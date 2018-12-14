/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_selector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:19:36 by wta               #+#    #+#             */
/*   Updated: 2018/12/12 15:03:27 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "print.h"

void	display_selector(char *path, char print_name, t_opts *opts)
{
	t_lst_ls	*lst;
	t_lst_ls	*lst_tmp;

	lst = NULL;
	if (print_name == 1)
		ft_printf("%s:\n", path);
	if ((lst = link_file(path, opts)) != NULL)
	{
		if (opts->cmp_fun != NULL)
			lst = lst_mergesort(lst, opts->cmp_fun);
		print_files(lst, opts);
		if (get_opt(opts, LS_REC) == 1)
		{
			lst_tmp = lst;
			while ((lst_tmp = find_dir(lst_tmp)) != NULL)
			{
				if ((get_opt(opts, LS_ALL) == 1
							&& is_curr_or_parent(lst_tmp->file->pdent) == 0)
						|| is_hidden(lst->file) == 0)
					ls_rec(lst_tmp->file->path, opts);
				lst_tmp = lst_tmp->next;
			}
		}
		lst_rm(lst, opts);
	}
}
