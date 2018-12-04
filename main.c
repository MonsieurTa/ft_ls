/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 06:24:01 by wta               #+#    #+#             */
/*   Updated: 2018/12/04 13:42:05 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_name(t_ls *lst)
{
	while (lst)
	{
		ft_printf("name :%s\n", lst->pdent->d_name);
		lst = lst->next;
	}
}

int	main(int ac, char **av)
{
	struct dirent	*pdent;
	DIR				*pdir;
	int				error;
	t_ls			*lst;
	t_ls			*node;

	if (ac != 1)
		return (0);
	if ((pdir = opendir(".")) == NULL)
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putchar('\n');
	}
	lst = NULL;
	while ((pdent = readdir(pdir)))
	{
		node = ls_new(pdent);
		ls_append(&lst, &node);
	}
	lst = ls_mergesort(lst, ls_size(lst));
	print_name(lst);
	/*
	 * reccursivite
	 */

	closedir(pdir);
	ls_rm(&lst);
	return (0);
}
