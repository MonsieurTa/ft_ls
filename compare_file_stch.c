/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_file_stch.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 11:41:21 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/08 13:59:45 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "compare_utils.h"

int		cmp_file_stch_rev(t_file *file1, t_file *file2)
{
	return (cmp_file_stch(file1, file2) * -1);
}

int		cmp_file_stch(t_file *file1, t_file *file2)
{
	int		res;

	if (file1 == NULL)
		return (file2 == NULL ? 0 : -1);
	else if (file2 == NULL)
		return (1);
	res = compare_timespec(&(file1->stat.st_ctimespec),
			&(file2->stat.st_ctimespec));
	if (res == 0)
		return (cmp_file_lexical(file1, file2));
	else
		return (res);
}
