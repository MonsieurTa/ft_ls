/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 06:24:01 by wta               #+#    #+#             */
/*   Updated: 2018/12/09 05:55:42 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"

int	main(int ac, char **av)
{
	t_opts	opts;
	char	c;


	if ((init_opts(ac, av, &opts, &c)) == -1)
		return (0);
	opts.ws = get_winsize();
	if (ac != 2)
		return (0);
	ls_rec(av[1], &opts);
	return (0);
}
