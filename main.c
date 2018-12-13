/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 06:24:01 by wta               #+#    #+#             */
/*   Updated: 2018/12/12 17:13:03 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "compare_utils.h"
#include "print.h"

static void	sort_params(int idx, int ac, char **av)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	i = idx;
	while (i < ac - 1)
	{
		if (ft_strcmp(av[i], av[i + 1]) > 0)
		{
			tmp = av[i];
			av[i] = av[i + 1];
			av[i + 1] = tmp;
			if (i > idx)
				i--;
		}
		else
			i++;
	}
}

int	main(int ac, char **av)
{
	t_opts	opts;
	char	c;
	int		nb_opts;
	int		idx;

	opts.mask = 0;
	def_opts_for_is_tty(&opts);
	if ((nb_opts = init_opts(ac - 1, av + 1, &opts, &c)) == -1)
		return (0);
	set_cmp_fun(&opts);
	set_winsize(&opts);
	set_tab_w(&opts);
	if (ac - 1 == nb_opts)
	{
		display_selector(".", ".", &opts);
		return (0);
	}
	else
	{
		idx = nb_opts;
		sort_params(idx, ac, av);
		while (idx < ac)
		{
			display_selector(av[idx], av[idx], &opts);
			idx++;
		}
	}
	return (0);
}
