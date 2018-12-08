/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_file_crea.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 09:13:21 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/08 13:42:35 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "compare_utils.h"

int		cmp_file_crea_rev(t_file *file1, t_file *file2)
{
	return (cmp_file_crea(file1, file2) * -1);
}

int		cmp_file_crea(t_file *file1, t_file *file2)
{
	int		res;

	if (file1 == NULL)
		return (file2 == NULL ? 0 : -1);
	else if (file2 == NULL)
		return (1);
#ifdef _DARWIN_FEATURE_64_BIT_INODE
	res = compare_timespec(&(file1->stat.st_birthtimespec),
			&(file2->stat.st_birthtimespec));
#else
	res = compare_timespec(&(file1->stat.st_ctimespec),
			&(file2->stat.st_ctimespec));
#endif
	if (res == 0)
		return (cmp_file_lexical(file1, file2));
	else
		return (res);
}
