/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:41:07 by wta               #+#    #+#             */
/*   Updated: 2018/12/11 08:51:59 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "options.h"

void	set_tab_w(t_opts *opts)
{
	if (get_opt(opts, LS_COLOR) == 1)
		opts->tab_w = 1;
	else
		opts->tab_w = 8;
}
