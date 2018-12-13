/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 06:24:01 by wta               #+#    #+#             */
/*   Updated: 2018/12/13 16:29:41 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "compare_utils.h"
#include "print.h"

int	main(int ac, char **av)
{
	t_lst_info	lst;
	t_opts		opts;
	char		c;
	int			nb_opts;
	int			idx;

	opts.mask = 0;
	def_opts_for_is_tty(&opts);
	if ((nb_opts = init_opts(ac - 1, av + 1, &opts, &c)) == -1)
		return (0);
	set_cmp_fun(&opts);
	set_winsize(&opts);
	set_tab_w(&opts);
	if (ac - 1 == nb_opts)
		display_selector(".", 0, &opts);
	else if (ac - 1 == nb_opts + 1)
	{
		display_selector(av[nb_opts + 1], 0, &opts);
		multiple_file(&lst, &opts, av[nb_opts + 1]);
		if (lst.head != NULL)
		{
			print_files(lst.head, &opts);
			lst_rm(lst.head, &opts);
		}
	}
	else
	{
		opts.has_dir = 0;
		idx = nb_opts + 1;
		while (idx < ac)
		{
			multiple_file(&lst, &opts, av[idx]);
			idx++;
		}
		if (lst.head != NULL)
		{
			print_files(lst.head, &opts);
			lst_rm(lst.head, &opts);
		}
		idx = nb_opts + 1;
		if (opts.has_dir == 1)
			ft_printf("\n");
		while (idx < ac)
		{
			display_selector(av[idx], 1, &opts);
			idx++;
		}
	}
	return (0);
}
