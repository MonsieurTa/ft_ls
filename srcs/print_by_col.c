/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_by_col.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:09:40 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/18 12:04:20 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "print.h"

static t_lst_ls	**init_col_tab(t_lst_ls *lst, int max_col, int max_row)
{
	t_lst_ls	**line;
	int			col;
	int			idx;

	if ((line = ft_memalloc(sizeof(t_lst_ls*) * (max_col + 1))) == NULL)
		return (NULL);
	col = 0;
	idx = 0;
	while (lst && col < max_col)
	{
		while (idx++ != col * (max_row + 1))
			lst = lst->next;
		line[col] = lst;
		col++;
	}
	return (line);
}

static int		print_col_el(t_file *file, t_opts *opts,
					char is_last_elem, int col_size)
{
	if (is_last_elem)
		return (ft_printf("%s%s%s%s",
					file->fields.color_start_static,
					(opts->has_file == 1) ? file->path : file->name,
					file->fields.color_end_static,
					file->fields.name_deco));
	else
		return (ft_printf("%s%s%s%s%-*s",
					file->fields.color_start_static,
					(opts->has_file == 1) ? file->path : file->name,
					file->fields.color_end_static,
					file->fields.name_deco,
					col_size - file->fields.name_with_deco_len, ""));
}

static void		init_col_fmt(t_opts *opts, t_col_fmt *col_fmt)
{
	col_fmt->col_size = opts->fmt.name_with_deco_max_s + opts->tab_w
		- (opts->fmt.name_with_deco_max_s % opts->tab_w);
	col_fmt->max_col = opts->ws.ws_col / col_fmt->col_size;
	col_fmt->max_row = ft_ceil((float)opts->fmt.lst_size
			/ (float)col_fmt->max_col);
	col_fmt->max_col = ft_ceil((float)opts->fmt.lst_size
			/ (float)col_fmt->max_row);
}

/*
** Affiche la liste de fichier par colonne (affichage minimal).
*/

int				print_by_col(t_opts *opts, t_lst_ls *lst)
{
	t_lst_ls	**line;
	int			row;
	int			col;
	t_col_fmt	col_fmt;

	init_col_fmt(opts, &col_fmt);
	if ((line = init_col_tab(lst, col_fmt.max_col, col_fmt.max_row)) == NULL)
		return (-1);
	row = -1;
	while (++row < col_fmt.max_row)
	{
		col = -1;
		while (++col < col_fmt.max_col && line[col] != NULL)
		{
			if (print_col_el(line[col]->file, opts,
					col + 1 == col_fmt.max_col, col_fmt.col_size) < 0)
				return (-1);
			line[col] = line[col]->next;
		}
		ft_putchar('\n');
	}
	free(line);
	return (0);
}
