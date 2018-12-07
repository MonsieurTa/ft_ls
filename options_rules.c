/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_rules.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 08:10:23 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/07 08:34:14 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "options_rules.h"

void	apply_rules_for_opt(t_opts *opts, t_opt_name opt_name)
{
	if (opt_name == LS_NOSORT)
		set_opt_val(opts, LS_ALL, 1);
	else if (opt_name == LS_NOOWN)
		set_opt_val(opts, LS_LONGF, 1);
	else if (opt_name == LS_NUMID)
		set_opt_val(opts, LS_LONGF, 1);
	else if (opt_name == LS_NOGRP)
		set_opt_val(opts, LS_LONGF, 1);
	else if (opt_name == LS_SIZESO)
		set_opt_val(opts, LS_TIMESO, 0);
	else if (opt_name == LS_TIMESO && get_opt(opts, LS_SIZESO) == 1)
		set_opt_val(opts, LS_TIMESO, 0);
	else if (opt_name == LS_CREATI)
		set_opt_val(opts, LS_ACCETI, 0);
	else if (opt_name == LS_ACCETI)
		set_opt_val(opts, LS_CREATI, 0);
}
