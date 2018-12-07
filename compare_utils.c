/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:11:41 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/07 16:19:05 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "options.h"
#include "ft_ls.h"
#include "compare_utils.h"

int		(*g_init_cmp_fun(t_opts *opts))(t_file *file1, t_file *file2)
{
	if (get_opt(opts, LS_SIZESO) == 1)
		return (NULL); //sortsize
	else if (get_opt(opts, LS_CREATI) == 1)
		return (NULL); //sortcreatime
	else if (get_opt(opts, LS_ACCETI) == 1)
		return (NULL); //sortaccetime
	else if (get_opt(opts, LS_TIMESO) == 1)
		return (NULL); //sortdeftime
	else
		return (NULL); //sortdef (lexical ?)
}
