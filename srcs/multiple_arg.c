/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:24:04 by wta               #+#    #+#             */
/*   Updated: 2018/12/17 13:37:26 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "file.h"
#include "error.h"
#include "print.h"

void	print_lst(t_lst_info *lst, t_opts *opts)
{
	if (lst->head != NULL)
	{
		print_files(lst->head, opts);
		lst_rm(lst->head, opts);
		lst->head = NULL;
		lst->tail = NULL;
	}
}

void	multiple_arg_dir(int idx, char **av, t_lst_info *lst, t_opts *opts)
{
	char	lst_was_not_null;

	lst_was_not_null = (lst->head != NULL ? 1 : 0);
	print_lst(lst, opts);
	if (lst_was_not_null == 1)
		ft_putchar('\n');
	display_selector(av[idx], 1, opts);
}

void	multiple_arg(int ac, char **av, t_opts *opts)
{
	t_lst_info	lst;
	t_stat		st_stat;
	int			idx;

	sort_params(ac, av, opts);
	lst.head = NULL;
	lst.tail = NULL;
	idx = 0;
	while (idx < ac)
	{
		if (lstat(av[idx], &st_stat) != -1)
		{
			if (S_ISDIR(st_stat.st_mode))
			{
				multiple_arg_dir(idx, av, &lst, opts);
				if (idx < ac - 1)
					ft_putchar('\n');
			}
			else
				multiple_file(&lst, opts, &st_stat, av[idx]);
		}
		else
			print_error(av[idx], 1, NULL);
		idx++;
	}
	print_lst(&lst, opts);
}
