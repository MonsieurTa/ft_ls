/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 11:09:53 by wta               #+#    #+#             */
/*   Updated: 2018/12/12 09:22:22 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "print.h"
#include "fields_utils.h"

/*
** Affiche la liste de fichier par ligne (affichage minimal).
*/

static int		print_by_line(t_opts *opts, t_lst_ls *lst, t_fmt *fmt)
{
	int			print_ret;

	while (lst != NULL)
	{
		if (ft_printf("%s\n", lst->file->fields.name) < 0)
			return (-1);
		lst = lst->next;
	}
	return (0);
}

static int		print_by_col(t_opts *opts, t_lst_ls *lst, t_fmt *fmt)
{
	t_lst_ls	**line;
	int			print_ret;
	t_lst_ls	*h_lst;
	int			idx;
	int			col;
	int			row;
	int			col_size = fmt->name_max_s + opts->tab_w - (fmt->name_max_s % opts->tab_w);
	int			max_col = opts->ws.ws_col / col_size;
	int			max_row = ft_ceil((float)fmt->lst_size / (float)max_col);

	max_col = ft_ceil((float)fmt->lst_size / (float)max_row);
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
					print_ret = ft_printf("%s", line[col]->file->fields.name);
				else
					print_ret = ft_printf("%-*s", col_size, line[col]->file->fields.name);
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

static int		print_with_long_f(t_opts *opts, t_lst_ls *lst, t_fmt *fmt)
{
	int			print_ret;

	while (lst != NULL)
	{
		if (ft_printf("%-*s %-*s %-*s\n",
					fmt->rights_max_s, lst->file->fields.rights,
					fmt->size_max_s, lst->file->fields.size,
					fmt->name_max_s, lst->file->fields.name) < 0)
			return (-1);
		lst = lst->next;
	}
	return (0);
}

int				print_files(t_lst_ls *lst, t_opts *opts)
{
	int		print_ret;
	t_fmt	fmt;
	char	*field;

	print_ret = 0;
	if (get_opt(opts, LS_BYLINE) == 1 || get_opt(opts, LS_BYCLMN) == 1)
	{
		if (init_minimum_fields_and_fmt(opts, lst, &fmt) == -1)
		{
			delete_minimum_fields(lst);
			return (-1);
		}
		if (get_opt(opts, LS_BYLINE) == 1)
			print_ret = print_by_line(opts, lst, &fmt);
		else
			print_ret = print_by_col(opts, lst, &fmt);
		delete_minimum_fields(lst);
	}
	else if(get_opt(opts, LS_LONGF) == 1)
	{
		if (init_all_fields_and_fmt(opts, lst, &fmt) == -1)
		{
			delete_all_fields(lst);
			return (-1);
		}
		print_ret = print_with_long_f(opts, lst, &fmt);
		delete_all_fields(lst);
	}
	return (print_ret);
}
