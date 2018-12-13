/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_tty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 08:21:05 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/11 08:32:22 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "options.h"

void	def_opts_for_is_tty(t_opts *opts)
{
	if (isatty(STDOUT_FILENO))
	{
		set_opt_val(opts, LS_BYCLMN, 1);
	}
	else
	{
		set_opt_val(opts, LS_BYLINE, 1);
	}
}
