/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 06:24:01 by wta               #+#    #+#             */
/*   Updated: 2018/12/08 13:45:57 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"

int	main(int ac, char **av)
{
	t_opts	opts;


	opts.ws = get_winsize();
	ft_printf("rows=%d cols=%d\n", opts.ws.ws_row, opts.ws.ws_col);
	if (ac != 2)
		return (0);
	ls_rec(av[1], &opts);
	return (0);
}
