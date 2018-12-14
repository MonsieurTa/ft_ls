/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_selector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:19:36 by wta               #+#    #+#             */
/*   Updated: 2018/12/14 15:34:09 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "print.h"
#include "error.h"

void	display_selector(char *path, char print_name, t_opts *opts)
{
	t_stat		st_stat;
	t_lst_ls	*lst;
	t_lst_info	lst_m;
	t_lst_ls	*lst_tmp;

	lst = NULL;
	if ((lstat(path, &st_stat)) == -1)
	{
		print_error(path, print_name, NULL);
		return ;
	}
	else if (S_ISREG(st_stat.st_mode) == 1)
	{
		lst_m.head = NULL;
		lst_m.tail = NULL;
		multiple_file(&lst_m, opts, &st_stat, path);
		if (lst_m.head != NULL)
		{
			print_files(lst_m.head, opts);
			lst_rm(lst_m.head, opts);
		}
	}
	else if (S_ISDIR(st_stat.st_mode) == 1 && (lst = link_file(path, &st_stat,opts)) != NULL)
	{
		if (print_name == 1)
			ft_printf("%s:\n", path);
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
