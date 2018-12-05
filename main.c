/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 06:24:01 by wta               #+#    #+#             */
/*   Updated: 2018/12/05 02:41:29 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_name(t_ls *lst)
{
	while (lst)
	{
		ft_printf("name: %s\n", lst->pdent->d_name);
		lst = lst->next;
	}
}

int		is_slash_ended(char *path)
{
	int	i;

	i = 0;
	while (path[i + 1])
		i++;
	return (path[i] == '/');
}

char	*ls_getpath(t_ls *parent, char *path)
{
	if (parent == NULL)
		return (path);
	if (!(path = ls_getpath(parent->parent, path)))
		return (NULL);
	if (!(is_slash_ended(path)))
		if (!(path = ft_strjoin(path, "/")))
			return (NULL);
	if (!(path = ft_strjoin(path, parent->pdent->d_name)))
		return (NULL);
	if (!(path = ft_strjoin(path, "/")))
		return (NULL);
	return (path);
}

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
	path = ls_getpath(parent, currpath);
	ft_printf("PATH %s\n", path);
	if (!(pdir = opendir(path)))
		return ;
	childs = NULL;
	while ((pdent = readdir(pdir)))
	{
		node = ls_new(pdent, parent);
		ls_append(&childs, &node);
	}
	childs = ls_mergesort(childs, ls_size(childs));
	h_childs = &childs;
	//print_name(childs);
	while (*childs->pdent->d_name == '.' || (ft_strcmp(childs->pdent->d_name, "..") == 0))
		childs = childs->next;
	ls_rec(parent->next, currpath);
	ls_rec(childs, currpath);
	ls_rm(h_childs);
	closedir(pdir);
}

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
		ft_putchar('\n');
	}
	lst = NULL;
	while ((pdent = readdir(pdir)))
	{
		node = ls_new(pdent, NULL);
		ls_append(&lst, &node);
	}
	lst = ls_mergesort(lst, ls_size(lst));
	print_name(lst);
	/*
	 * reccursivite
	 */
	ls_rec(lst, av[1]);
	closedir(pdir);
	ls_rm(&lst);
	return (0);
}
