/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_file_lexical.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 09:16:15 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/08 11:07:57 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "compare_utils.h"

int		cmp_file_lexical_rev(t_file *file1, t_file *file2)
{
	return (cmp_file_lexical(file1, file2) * -1);
}

int		cmp_file_lexical(t_file *file1, t_file *file2)
{
	if (file1 == NULL)
		return (file2 == NULL ? 0 : -1);
	else if (file2 == NULL)
		return (1);
	return (ft_strcmp(file1->pdent->d_name, file2->pdent->d_name));
}
