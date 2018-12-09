/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 11:09:53 by wta               #+#    #+#             */
/*   Updated: 2018/12/09 07:21:10 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include "ft_ls.h"
#include "options.h"

int			get_min_w(t_lst_ls *lst, int *len)
{
	t_lst_ls	*tmp;
	int			filename_w;
	int			min_w;

	tmp = NULL;
	min_w = 0;
	if (lst)
	{
		tmp = lst;
		while (tmp)
		{
			filename_w = ft_strlen(tmp->file->pdent->d_name);
			min_w = (filename_w > min_w) ? filename_w + 1 : min_w;
			tmp = tmp->next;
			(*len)++;
		}
	}
	return (min_w);
}

int		ft_ceil(float x)
{
	int	ix;

	ix = (int)x;
	if (x == (float)ix)
		return (ix);
	return (ix + 1);
}

t_lst_ls	*skip_hidden(t_lst_ls *lst)
{
	if (lst)
		while (lst && *lst->file->pdent->d_name == '.')
			lst = lst->next;
	return (lst);
}

void		get_fmt(t_fmt *fmt, t_lst_ls *lst, t_opts *opts)
{
	fmt->len_lst = 0;
	fmt->min_w = get_min_w(lst, &fmt->len_lst);
	fmt->min_w = (fmt->min_w == 0) ? 1 : fmt->min_w;
	fmt->max_col = opts->ws.ws_col / fmt->min_w;
	fmt->max_row = ft_ceil((float)fmt->len_lst / (float)fmt->max_col);
	fmt->max_col = ft_ceil((float)fmt->len_lst / (float)fmt->max_row);
}

void		print_by_col(t_lst_ls *lst, t_fmt fmt)
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

	get_fmt(&fmt, lst, opts);
	print_by_col(lst, fmt);
}
