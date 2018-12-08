/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_file_acce.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 09:14:35 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/08 09:15:11 by fwerner          ###   ########.fr       */
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
	return (0);
}
