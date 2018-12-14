/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 11:09:53 by wta               #+#    #+#             */
/*   Updated: 2018/12/14 11:31:44 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "print.h"
#include "fields_utils.h"

/*
** Affiche la liste de fichier par ligne (affichage minimal).
*/

static int		print_by_line(t_lst_ls *lst)
{
	while (lst != NULL)
	{
		if (ft_printf("%s%s%s%s\n",
					lst->file->fields.color_start_static,
					lst->file->pdent->d_name,
					lst->file->fields.color_end_static,
					lst->file->fields.name_deco) < 0)
			return (-1);
		lst = lst->next;
	}
	return (0);
}

/*
** Affiche la liste de fichier par colonne (affichage minimal).
*/

static int		print_by_col(t_opts *opts, t_lst_ls *lst)
{
	t_lst_ls	**line;
	int			print_ret;
	t_lst_ls	*h_lst;
	int			idx;
	int			row;
	int			col;
	int			col_size = opts->fmt.name_with_deco_max_s + opts->tab_w - (opts->fmt.name_with_deco_max_s % opts->tab_w);
	int			max_col = opts->ws.ws_col / col_size;
	int			max_row = ft_ceil((float)opts->fmt.lst_size / (float)max_col);

	max_col = ft_ceil((float)opts->fmt.lst_size / (float)max_row);
	h_lst = lst;
	if ((line = ft_memalloc(sizeof(t_lst_ls*) * (max_col + 1))) == NULL)
		return (-1);
	col = 0;
	idx = 0;
	while (lst && col < max_col)
	{
		while (idx++ != col * (max_row + 1))
			lst = lst->next;
		line[col] = lst;
		col++;
	}
	row = 0;
	while (row < max_row)
	{
		col = 0;
		while (col < max_col)
		{
			if (line[col])
			{
				if (col + 1 == max_col)
					print_ret = ft_printf("%s%s%s%s",
							line[col]->file->fields.color_start_static,
							line[col]->file->pdent->d_name,
							line[col]->file->fields.color_end_static,
							line[col]->file->fields.name_deco);
				else
					print_ret = ft_printf("%s%s%s%s%-*s",
							line[col]->file->fields.color_start_static,
							line[col]->file->pdent->d_name,
							line[col]->file->fields.color_end_static,
							line[col]->file->fields.name_deco,
							col_size - line[col]->file->fields.name_with_deco_len, "");
				if (print_ret < 0)
					return (-1);
				line[col] = line[col]->next;
			}
			else
				break ;
			col++;
		}
		ft_putchar('\n');
		row++;
	}
	if (line)
		free(line);
	return (0);
}

/*
** Affiche la liste de fichier par ligne en affichage complet.
*/

static int		print_with_long_f(t_opts *opts, t_lst_ls *lst)
{
	char	space_between_guid_and_uid;

	if (get_opt(opts, LS_NOOWN) == 1 || get_opt(opts, LS_NOGRP) == 1)
		space_between_guid_and_uid = 0;
	else
		space_between_guid_and_uid = 2;
	if (ft_printf("total %lld\n", opts->fmt.dir_block_count) == -1)
		return (-1);
	while (lst != NULL)
	{
		if (ft_printf("%s %*s %-*s%*s%-*s  %*s %s%s%s%s\n",
					lst->file->fields.rights,
					opts->fmt.hard_link_max_s, lst->file->fields.hard_link,
					opts->fmt.user_max_s, lst->file->fields.user,
					space_between_guid_and_uid, "",
					opts->fmt.group_max_s, lst->file->fields.group,
					opts->fmt.size_max_s, lst->file->fields.size,
					lst->file->fields.color_start_static,
					lst->file->pdent->d_name,
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
		print_ret = print_by_line(lst);
	else if (get_opt(opts, LS_BYCLMN) == 1)
		print_ret = print_by_col(opts, lst);
	else if(get_opt(opts, LS_LONGF) == 1)
		print_ret = print_with_long_f(opts, lst);
	return (print_ret);
}
