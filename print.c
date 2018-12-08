/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 11:09:53 by wta               #+#    #+#             */
/*   Updated: 2018/12/08 15:01:26 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include "ft_ls.h"
#include "options.h"

int		get_min_w(t_lst_ls *lst, int *len)
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

void	print_files(t_lst_ls *lst, t_opts *opts)
{
	int	max_col;
	int	max_row;
	int	min_w;
	int	len;

	len = 0;
	min_w = get_min_w(lst, &len);
	max_col = opts->ws.ws_col / min_w;
	max_row = ft_ceil((float)len / (float)max_col);
	ft_printf("max col = %d max_row = %d\n", max_col, max_row);

}
