/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 11:09:53 by wta               #+#    #+#             */
/*   Updated: 2018/12/11 09:03:55 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "print.h"
#include "set_field.h"

void		print_by_col(t_lst_ls *lst, t_fmt fmt, t_opts *opts)
{
	t_lst_ls	*h_lst;
	int			idx;
	int			row;
	int			col;

	h_lst = lst;
	row = 0;
	while (lst && row < fmt.max_row)
	{
		idx = 0;
		col = 0;
		while (lst && col < fmt.max_col)
		{

			if (idx == row + col * fmt.max_row)
			{
				if (col + 1 == fmt.max_col)
					ft_printf("%s", lst->file->pdent->d_name);
				else
					ft_printf("%-*s", fmt.min_w, lst->file->pdent->d_name);
				col++;
			}
			lst = lst->next;
			idx++;
		}
		ft_putchar('\n');
		lst = h_lst;
		row++;
	}
}

void		print_files(t_lst_ls *lst, t_opts *opts)
{
	t_fmt	fmt;
	char	*field;

	get_fmt(&fmt, lst, opts);
//	print_by_col(lst, fmt, opts);
	while (lst)
	{
		set_field_rights(opts, lst->file, &field);
		ft_printf("%s %s\n", field, lst->file->pdent->d_name);
		free(field);
		lst = lst->next;
	}
}
