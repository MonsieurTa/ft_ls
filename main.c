/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 06:24:01 by wta               #+#    #+#             */
/*   Updated: 2018/12/04 11:30:46 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int ac, char **av)
{
	struct dirent	*pdent;
	DIR				*pdir;
	int				error;
	t_ls			*lst;
	t_ls			*node;

	if (ac != 2)
		return (0);
	if ((pdir = opendir(av[1])) == NULL)
	{
		ft_putstr_fd(strerror(errno), 2);
		return (0);
	}
	lst = NULL;
	while ((pdent = readdir(pdir)))
	{
		node = ls_new(pdent);
		ls_append(&lst, &node);
	}
	ft_printf("size = %d\n", ls_size(lst));
	return (0);
}
