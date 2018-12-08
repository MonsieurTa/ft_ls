/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_file_time.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 09:15:34 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/08 09:16:05 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "compare_utils.h"

int		cmp_file_time_rev(t_file *file1, t_file *file2)
{
	return (cmp_file_time(file1, file2) * -1);
}

int		cmp_file_time(t_file *file1, t_file *file2)
{
	return (0);
}
