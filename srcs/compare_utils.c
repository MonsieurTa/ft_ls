/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:11:41 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/11 08:47:28 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "options.h"
#include "ft_ls.h"
#include "compare_utils.h"

/*
** Set le pointeur cmp_fun de opts a la fonction reverse correspondant
** aux parametres de tri.
*/

static void		set_cmp_fun_rev(t_opts *opts)
{
	if (get_opt(opts, LS_SIZESO) == 1)
		opts->cmp_fun = cmp_file_size_rev;
	else if (get_opt(opts, LS_STCHTI) == 1 && get_opt(opts, LS_TIMESO) == 1)
		opts->cmp_fun = cmp_file_stch_rev;
	else if (get_opt(opts, LS_CREATI) == 1 && get_opt(opts, LS_TIMESO) == 1)
		opts->cmp_fun = cmp_file_crea_rev;
	else if (get_opt(opts, LS_ACCETI) == 1 && get_opt(opts, LS_TIMESO) == 1)
		opts->cmp_fun = cmp_file_acce_rev;
	else if (get_opt(opts, LS_TIMESO) == 1)
		opts->cmp_fun = cmp_file_time_rev;
	else
		opts->cmp_fun = cmp_file_lexical_rev;
}

void			set_cmp_fun(t_opts *opts)
{
	if (get_opt(opts, LS_NOSORT) == 1)
		opts->cmp_fun = NULL;
	else if (get_opt(opts, LS_REVSO) == 1)
		set_cmp_fun_rev(opts);
	else if (get_opt(opts, LS_SIZESO) == 1)
		opts->cmp_fun = cmp_file_size;
	else if (get_opt(opts, LS_STCHTI) == 1 && get_opt(opts, LS_TIMESO) == 1)
		opts->cmp_fun = cmp_file_stch;
	else if (get_opt(opts, LS_CREATI) == 1 && get_opt(opts, LS_TIMESO) == 1)
		opts->cmp_fun = cmp_file_crea;
	else if (get_opt(opts, LS_ACCETI) == 1 && get_opt(opts, LS_TIMESO) == 1)
		opts->cmp_fun = cmp_file_acce;
	else if (get_opt(opts, LS_TIMESO) == 1)
		opts->cmp_fun = cmp_file_time;
	else
		opts->cmp_fun = cmp_file_lexical;
}
