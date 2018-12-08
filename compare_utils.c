/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:11:41 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/08 09:24:46 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "options.h"
#include "ft_ls.h"
#include "compare_utils.h"

int		(*g_get_cmp_fun(t_opts *opts))(t_file *file1, t_file *file2)
{
	if (get_opt(opts, LS_NOSORT) == 1)
		return (NULL);
	if (get_opt(opts, LS_REVSO) == 1)
	{
		if (get_opt(opts, LS_SIZESO) == 1)
			return (cmp_file_size_rev);
		else if (get_opt(opts, LS_CREATI) == 1)
			return (cmp_file_crea_rev);
		else if (get_opt(opts, LS_ACCETI) == 1)
			return (cmp_file_acce_rev);
		else if (get_opt(opts, LS_TIMESO) == 1)
			return (cmp_file_time_rev);
		return (cmp_file_lexical_rev);
	}
	if (get_opt(opts, LS_SIZESO) == 1)
		return (cmp_file_size);
	else if (get_opt(opts, LS_CREATI) == 1)
		return (cmp_file_crea);
	else if (get_opt(opts, LS_ACCETI) == 1)
		return (cmp_file_acce);
	else if (get_opt(opts, LS_TIMESO) == 1)
		return (cmp_file_time);
	return (cmp_file_lexical);
}
