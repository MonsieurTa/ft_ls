/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 06:24:01 by wta               #+#    #+#             */
/*   Updated: 2018/12/12 14:44:25 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "compare_utils.h"
#include "print.h"

int	main(int ac, char **av)
{
	t_opts	opts;
	char	c;
	int		nb_opts;

	opts.mask = 0;
	def_opts_for_is_tty(&opts);
	if ((nb_opts = init_opts(ac - 1, av + 1, &opts, &c)) == -1)
		return (0);
	set_cmp_fun(&opts);
	set_winsize(&opts);
	set_tab_w(&opts);
	if (ac - nb_opts != 2)
		return (0);
	display_selector(av[nb_opts + 1], 0, &opts);
	return (0);
}
