/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_file_acce.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 09:14:35 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/12 12:36:37 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "compare_utils.h"

int		cmp_file_acce_rev(t_file *file1, t_file *file2)
{
	return (cmp_file_acce(file1, file2) * -1);
}

int		cmp_file_acce(t_file *file1, t_file *file2)
{
	int		res;

	res = compare_timespec(&(file1->stat.st_atimespec),
			&(file2->stat.st_atimespec));
	if (res == 0)
		return (cmp_file_lexical(file1, file2));
	else
		return (res);
}
