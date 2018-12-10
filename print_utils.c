/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 05:52:59 by wta               #+#    #+#             */
/*   Updated: 2018/12/10 06:19:53 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int			ft_ceil(float x)
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
