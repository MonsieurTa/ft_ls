/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:24:04 by wta               #+#    #+#             */
/*   Updated: 2018/12/17 12:08:05 by wta              ###   ########.fr       */
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
	}
}

void	multiple_arg_dir(int idx, char **av, t_lst_info *lst, t_opts *opts)
{
	print_lst(lst, opts);
	display_selector(av[idx], 1, opts);
}

void	multiple_arg(int ac, char **av, int nb_opts, t_opts *opts)
{
	t_lst_info	lst;
	t_stat		st_stat;
	int			idx;

	idx = nb_opts + 1;
	sort_params(idx, ac, av);
	lst.head = NULL;
	lst.tail = NULL;
	while (idx < ac)
	{
		if (lstat(av[idx], &st_stat) != -1)
		{
			if (S_ISREG(st_stat.st_mode) == 1)
				multiple_file(&lst, opts, &st_stat, av[idx]);
			else if (S_ISDIR(st_stat.st_mode) == 1)
				multiple_arg_dir(idx, av, &lst, opts);
			else
				print_lst(&lst, opts);
			if (idx < ac - 1)
				ft_putchar('\n');
		}
		else
			print_error(av[idx], 1, NULL);
		idx++;
	}
}

void	swap(int *i, int idx, char **av)
{
	char	*tmp;

	tmp = av[*i];
	av[*i] = av[*i + 1];
	av[*i + 1] = tmp;
	if (*i > idx)
		(*i)--;
}

void	sort_params(int idx, int ac, char **av)
{
	t_lst_info	files;
	t_stat		st1;
	t_stat		st2;
	int			i;

	files.head = NULL;
	files.tail = NULL;
	i = idx;
	while (i < ac - 1)
	{
		if (lstat(av[i], &st1) == 0 && lstat(av[i + 1], &st2) == 0)
		{
			if ((S_ISREG(st2.st_mode) == 1 && S_ISDIR(st1.st_mode) == 1)
				|| ((st2.st_mode & S_IXUSR) && (st1.st_mode & S_IXUSR) == 0))
				swap(&i, idx, av);
			else
				i++;
		}
		else if (lstat(av[i], &st1) == 0 && lstat(av[i + 1], &st2) == -1)
			swap(&i, idx, av);
		else
			i++;
	}
}
