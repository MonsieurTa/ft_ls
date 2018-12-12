/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_rules.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 08:10:23 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/11 08:08:54 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "options_rules.h"

/*
** Met a jour les options selon si LS_NOSORT a ete passe.
*/

static int		process_no_sort_opt(t_opts *opts, t_opt_name opt_name)
{
	if (opt_name == LS_NOSORT)
	{
		set_opt_val(opts, LS_ALL, 1);
		set_opt_val(opts, LS_REVSO, 0);
		set_opt_val(opts, LS_SIZESO, 0);
		set_opt_val(opts, LS_TIMESO, 0);
		return (1);
	}
	return (0);
}

/*
** Met a jour les options selon si un modificateur de temps a ete passe.
*/

static int		process_time_modificator(t_opts *opts, t_opt_name opt_name)
{
	if (opt_name == LS_STCHTI)
	{
		set_opt_val(opts, LS_ACCETI, 0);
		set_opt_val(opts, LS_CREATI, 0);
	}
	else if (opt_name == LS_CREATI)
	{
		set_opt_val(opts, LS_STCHTI, 0);
		set_opt_val(opts, LS_ACCETI, 0);
	}
	else if (opt_name == LS_ACCETI)
	{
		set_opt_val(opts, LS_STCHTI, 0);
		set_opt_val(opts, LS_CREATI, 0);
	}
	else
		return (0);
	return (1);
}

/*
** Met a jour les options selon si un modificateur de format a ete passe.
*/

static int		process_format_modificator(t_opts *opts, t_opt_name opt_name)
{
	if (opt_name == LS_NOOWN || opt_name == LS_NUMID
			|| opt_name == LS_NOGRP || opt_name == LS_LONGF)
	{
		set_opt_val(opts, LS_BYLINE, 0);
		set_opt_val(opts, LS_BYCLMN, 0);
		set_opt_val(opts, LS_LONGF, 1);
	}
	else if (opt_name == LS_BYLINE)
	{
		set_opt_val(opts, LS_BYCLMN, 0);
		set_opt_val(opts, LS_LONGF, 0);
	}
	else if (opt_name == LS_BYCLMN)
	{
		set_opt_val(opts, LS_BYLINE, 0);
		set_opt_val(opts, LS_LONGF, 0);
	}
	else
		return (0);
	return (1);
}

void			apply_rules_for_opt(t_opts *opts, t_opt_name opt_name)
{
	if (process_no_sort_opt(opts, opt_name) == 1)
		return ;
	else if (process_time_modificator(opts, opt_name) == 1)
		return ;
	else if (process_format_modificator(opts, opt_name) == 1)
		return ;
	else if (opt_name == LS_REVSO && get_opt(opts, LS_NOSORT) == 1)
		set_opt_val(opts, LS_REVSO, 0);
	else if (opt_name == LS_SIZESO)
	{
		set_opt_val(opts, LS_TIMESO, 0);
		if (get_opt(opts, LS_NOSORT) == 1)
			set_opt_val(opts, LS_SIZESO, 0);
	}
	else if (opt_name == LS_TIMESO && (get_opt(opts, LS_SIZESO) == 1
				|| get_opt(opts, LS_NOSORT) == 1))
		set_opt_val(opts, LS_TIMESO, 0);
	else if (opt_name == LS_CREATI)
		set_opt_val(opts, LS_ACCETI, 0);
	else if (opt_name == LS_ACCETI)
		set_opt_val(opts, LS_CREATI, 0);
}
