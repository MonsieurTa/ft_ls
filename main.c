/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 06:24:01 by wta               #+#    #+#             */
/*   Updated: 2018/12/06 10:37:31 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
void	ls_rec(t_ls *parent, char *currpath)
{
	struct dirent	*pdent;
	DIR				*pdir;
	t_ls			**h_childs;
	t_ls			*childs;
	t_ls			*node;
	char			*path;

	while (parent && (parent->pdent->d_type != DT_DIR
				|| *parent->pdent->d_name == '.' || ft_strcmp(parent->pdent->d_name, "..") == 0))
		parent = parent->next;
	if (!parent)
		return ;
	if (!(path = ls_getpath(parent, currpath)))
		return ;
	if ((pdir = opendir(path)) == NULL)
	{
		ft_strdel(&path);
		return ;
	}
	ft_printf("\n%s\n", path);
	childs = NULL;
	node = NULL;
	while ((pdent = readdir(pdir)))
	{
		node = ls_new(*pdent, parent);
		ls_append(&childs, &node);
	}
	childs = ls_mergesort(childs, ls_size(childs));
	h_childs = &childs;
	ls_rec(childs, currpath);
	ls_rm(h_childs);
	ls_rec(parent->next, currpath);
	closedir(pdir);
	ft_strdel(&path);
}
*/
int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);

	return (0);
}
