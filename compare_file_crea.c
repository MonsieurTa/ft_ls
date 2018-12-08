/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_file_crea.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 09:13:21 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/08 09:14:27 by fwerner          ###   ########.fr       */
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
	return (0);
}
