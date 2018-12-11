/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_selector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:19:36 by wta               #+#    #+#             */
/*   Updated: 2018/12/11 15:48:46 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "print.h"

void	display_selector(char *path, char *currdir, t_opts *opts)
{
	t_lst_ls	*lst;

	lst = NULL;
	if (get_opt(opts, LS_REC) == 1)
		ls_rec(path, currdir, opts);
	else
	{
		if ((lst = link_file(path, opts)) != NULL)
		{
			print_files(lst, opts);
			lst_rm(lst);
		}
	}
}
