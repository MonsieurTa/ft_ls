/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_file_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 09:10:56 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/12 12:36:27 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "compare_utils.h"

int		cmp_file_size_rev(t_file *file1, t_file *file2)
{
	return (cmp_file_size(file1, file2) * -1);
}

int		cmp_file_size(t_file *file1, t_file *file2)
{
	if (file1->stat.st_size < file2->stat.st_size)
		return (-1);
	else if (file1->stat.st_size > file2->stat.st_size)
		return (1);
	return (cmp_file_lexical(file1, file2));
}
