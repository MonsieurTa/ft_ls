/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:24:04 by wta               #+#    #+#             */
/*   Updated: 2018/12/18 14:14:23 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "file.h"
#include "error.h"
#include "print.h"

static void	null_lst_info(t_lst_info *lst)
{
	lst->head = NULL;
	lst->tail = NULL;
}

void		print_lst(t_lst_info *lst, t_opts *opts)
{
	if (lst->head != NULL)
	{
		print_files(lst->head, opts);
		lst_rm(lst->head, opts);
		null_lst_info(lst);
	}
}

void		multiple_arg_dir(int idx, char **av, t_lst_info *lst, t_opts *opts)
{
	char	lst_was_not_null;

	lst_was_not_null = (lst->head != NULL ? 1 : 0);
	print_lst(lst, opts);
	if (lst_was_not_null == 1)
		ft_putchar('\n');
	display_selector(av[idx], 1, opts);
}

void		multiple_arg(int ac, char **av, t_opts *opts)
{
	t_lst_info	lst;
	t_stat		st_stat;
	int			idx;

	init_fmt(opts);
	sort_params(ac, av, opts);
	null_lst_info(&lst);
	idx = -1;
	while (++idx < ac)
	{
		if (lstat(av[idx], &st_stat) != -1)
		{
			if (S_ISDIR(st_stat.st_mode) && get_opt(opts, LS_DIRASF) == 0)
			{
				multiple_arg_dir(idx, av, &lst, opts);
				if (idx < ac - 1)
					ft_putchar('\n');
			}
			else
				multiple_file(&lst, opts, av[idx]);
		}
		else
			print_error(av[idx], 3, NULL, opts);
	}
	print_lst(&lst, opts);
}
