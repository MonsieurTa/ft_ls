/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 12:07:40 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/17 12:12:13 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "options.h"
#include "file.h"

static void		swap_param(int idx1, int idx2, char **av)
{
	char	*tmp;

	tmp = av[idx1];
	av[idx1] = av[idx2];
	av[idx2] = tmp;
}

static int		compare_files(t_stat *fst1, t_stat *fst2,
		int (*cmp_fun)(t_file *file1, t_file *file2))
{
	t_dirent	fpdent1;
	t_dirent	fpdent2;
	t_file		file1;
	t_file		file2;

	if (cmp_fun != NULL)
	{
		file1.stat = *fst1;
		file2.stat = *fst2;
		file1.pdent = &fpdent1;
		file2.pdent = &fpdent2;
		file1.pdent->d_name[0] = '\0';
		file2.pdent->d_name[0] = '\0';
		return (cmp_fun(&file1, &file2));
	}
	else
	{
		return (0);
	}
}

static int		pathcmp(char *path1, char *path2,
		int (*cmp_fun)(t_file *file1, t_file *file2), int reverse_sort)
{
	if (cmp_fun != NULL)
	{
		if (reverse_sort == 1)
			return (ft_strcmp(path1, path2) * -1);
		else
			return (ft_strcmp(path1, path2));
	}
	else
	{
		return (0);
	}
}

static int		compare_param(char *param1, char *param2, t_opts *opts)
{
	t_stat		st1;
	t_stat		st2;
	int			st_ret1;
	int			st_ret2;
	int			cmp_ret;

	st_ret1 = lstat(param1, &st1);
	st_ret2 = lstat(param2, &st2);
	if (st_ret1 != 0 || st_ret2 != 0)
	{
		if (st_ret1 != 0)
			return (st_ret2 != 0 ? pathcmp(param1, param2, opts->cmp_fun, 0)
					: -1);
		else
			return (1);
	}
	if (S_ISDIR(st1.st_mode) != S_ISDIR(st2.st_mode))
		return (S_ISDIR(st1.st_mode) ? 1 : -1);
	cmp_ret = compare_files(&st1, &st2, opts->cmp_fun);
	return (cmp_ret == 0 ? pathcmp(param1, param2, opts->cmp_fun,
				get_opt(opts, LS_REVSO)) : cmp_ret);
}

void			sort_params(int ac, char **av, t_opts *opts)
{
	char		is_sorted;
	int			i;

	is_sorted = 0;
	while (is_sorted == 0)
	{
		is_sorted = 1;
		i = 0;
		while (i < ac - 1)
		{
			if (compare_param(av[i], av[i + 1], opts) > 0)
			{
				is_sorted = 0;
				swap_param(i, i + 1, av);
			}
			++i;
		}
	}
}
