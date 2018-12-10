/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 06:24:01 by wta               #+#    #+#             */
/*   Updated: 2018/12/10 10:09:22 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "compare_utils.h"

int	main(int ac, char **av)
{
	t_opts	opts;
	char	c;
	int		nb_opts;

	if ((nb_opts = init_opts(ac - 1, av + 1, &opts, &c)) == -1)
		return (0);
	opts.cmp_fun = g_get_cmp_fun(&opts);
	opts.ws = get_winsize();
	opts.tab_w = 1;
	if (ac - nb_opts != 2)
		return (0);
	ls_rec(av[nb_opts + 1], av[nb_opts + 1], &opts);
	return (0);
}
