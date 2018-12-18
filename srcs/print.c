/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 11:09:53 by wta               #+#    #+#             */
/*   Updated: 2018/12/18 12:03:58 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "print.h"
#include "fields_utils.h"

/*
** Affiche la liste de fichier par ligne (affichage minimal).
*/

static int		print_by_line(t_lst_ls *lst, t_opts *opts)
{
	while (lst != NULL)
	{
		if (ft_printf("%s%s%s%s\n",
					lst->file->fields.color_start_static,
					(opts->has_file == 1) ?
					lst->file->path : lst->file->name,
					lst->file->fields.color_end_static,
					lst->file->fields.name_deco) < 0)
			return (-1);
		lst = lst->next;
	}
	return (0);
}

/*
** Affiche la liste de fichier par ligne en affichage complet.
*/

static int		print_with_long_f(t_opts *opts, t_lst_ls *lst)
{
	char	space_between_guid_and_uid;

	space_between_guid_and_uid = (get_opt(opts, LS_NOOWN) == 1
			|| get_opt(opts, LS_NOGRP) == 1) ? 0 : 2;
	if ((opts->has_file != 1)
			&& ft_printf("total %lld\n", opts->fmt.dir_block_count) == -1)
		return (-1);
	while (lst != NULL)
	{
		if (ft_printf("%s %*s %-*s%*s%-*s  %*s %s %s%s%s%s\n",
			lst->file->fields.rights, opts->fmt.hard_link_max_s,
			lst->file->fields.hard_link, opts->fmt.user_max_s,
			lst->file->fields.user, space_between_guid_and_uid,
			"", opts->fmt.group_max_s, lst->file->fields.group,
			opts->fmt.size_max_s, lst->file->fields.size,
			lst->file->fields.date, lst->file->fields.color_start_static,
			(opts->has_file == 1) ? lst->file->path : lst->file->name,
			lst->file->fields.color_end_static,
			lst->file->fields.name_deco) < 0)
			return (-1);
		lst = lst->next;
	}
	return (0);
}

int				print_files(t_lst_ls *lst, t_opts *opts)
{
	int		print_ret;

	print_ret = 0;
	if (get_opt(opts, LS_BYLINE) == 1)
		print_ret = print_by_line(lst, opts);
	else if (get_opt(opts, LS_BYCLMN) == 1)
		print_ret = print_by_col(opts, lst);
	else if (get_opt(opts, LS_LONGF) == 1)
		print_ret = print_with_long_f(opts, lst);
	opts->has_file = 0;
	return (print_ret);
}
