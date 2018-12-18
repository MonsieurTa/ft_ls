/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 06:24:01 by wta               #+#    #+#             */
/*   Updated: 2018/12/17 20:19:05 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "compare_utils.h"
#include "print.h"
#include "error.h"

int	main(int ac, char **av)
{
	t_opts		opts;
	char		c;
	int			nb_opts;

	opts.mask = 0;
	opts.has_file = 0;
	def_opts_for_is_tty(&opts);
	if ((nb_opts = init_opts(ac - 1, av + 1, &opts, &c)) == -1)
		return (print_usage(ac > 0 ? av[0] : "ft_ls", c));
	set_cmp_fun(&opts);
	set_winsize(&opts);
	set_tab_w(&opts);
	if (ac - 1 == nb_opts)
		display_selector(".", 0, &opts);
	else if (ac - 1 == nb_opts + 1)
		display_selector(av[nb_opts + 1], 0, &opts);
	else
		multiple_arg(ac - 1 - nb_opts, av + 1 + nb_opts, &opts);
	return (0);
}
