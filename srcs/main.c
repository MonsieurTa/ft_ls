/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 06:24:01 by wta               #+#    #+#             */
/*   Updated: 2018/12/14 16:09:23 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "compare_utils.h"
#include "print.h"
#include "error.h"

static void	sort_params(int idx, int ac, char **av)
{
	t_lst_info	files;
	t_stat		st_stat1;
	t_stat		st_stat2;
	char		*tmp;
	int	i;

	files.head = NULL;
	files.tail = NULL;
	i = idx;
	while (i < ac - 1)
	{
		if (lstat(av[i], &st_stat1) == 0 && lstat(av[i + 1], &st_stat2) == 0)
		{
			if ((S_ISREG(st_stat2.st_mode) == 1
				&& S_ISDIR(st_stat1.st_mode) == 1)
			|| ((st_stat2.st_mode & S_IXUSR)
				&& (st_stat1.st_mode & S_IXUSR) == 0))
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
		else if (lstat(av[i], &st_stat1) == 0 && lstat(av[i + 1], &st_stat2) == -1)
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
	t_lst_info	lst;
	t_stat		st_stat;
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
		display_selector(av[nb_opts + 1], 0, &opts);
	else
	{
		idx = nb_opts + 1;
		sort_params(idx, ac, av);
		lst.head = NULL;
		lst.tail = NULL;
		while (idx < ac)
		{
			if (lstat(av[idx], &st_stat) != -1)
			{
				if (S_ISREG(st_stat.st_mode) == 1)
					multiple_file(&lst, &opts, &st_stat, av[idx]);
				else if (S_ISDIR(st_stat.st_mode) == 1)
				{
					if (lst.head != NULL)
					{
						print_files(lst.head, &opts);
						lst_rm(lst.head, &opts);
						ft_putchar('\n');
					}
					display_selector(av[idx], 1, &opts);
				}
				else if (lst.head != NULL)
				{
					print_files(lst.head, &opts);
					lst_rm(lst.head, &opts);
				}
			}
			else
				print_error(av[idx], 1, NULL);
			idx++;
		}
	}
	return (0);
}
