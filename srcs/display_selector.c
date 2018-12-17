/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_selector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:19:36 by wta               #+#    #+#             */
/*   Updated: 2018/12/17 14:16:18 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "print.h"
#include "error.h"

static void	display_reg(char *path, t_lst_info *lst_m, t_opts *opts, t_stat *st)
{
	lst_m->head = NULL;
	lst_m->tail = NULL;
	multiple_file(lst_m, opts, st, path);
	if (lst_m->head != NULL)
	{
		print_files(lst_m->head, opts);
		lst_rm(lst_m->head, opts);
	}
}

static void	display_dir(char *path, char print_n, t_lst_ls *lst, t_opts *opts)
{
	t_lst_ls	*lst_tmp;

	if (print_n == 1)
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

void		display_selector(char *path, char print_name, t_opts *opts)
{
	t_stat		st_stat;
	t_lst_ls	*lst;
	t_lst_info	lst_m;

	lst = NULL;
	if ((lstat(path, &st_stat)) == -1)
	{
		print_error(path, print_name, NULL);
		return ;
	}
	else if (S_ISDIR(st_stat.st_mode) && get_opt(opts, LS_DIRASF) == 0)
	{
		if ((lst = link_file(path, opts)) != NULL)
			display_dir(path, print_name, lst, opts);
		else
			print_error(path, 1, &st_stat);
	}
	else
		display_reg(path, &lst_m, opts, &st_stat);
}
