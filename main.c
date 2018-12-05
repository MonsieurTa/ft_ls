/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 06:24:01 by wta               #+#    #+#             */
/*   Updated: 2018/12/05 08:29:25 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_name(t_ls *lst)
{
	while (lst)
	{
		while (lst && (*lst->pdent->d_name == '.' || ft_strcmp(lst->pdent->d_name, "..") == 0))
			lst = lst->next;
		if (lst)
		{
			ft_printf("name: %s\n", lst->pdent->d_name);
			lst = lst->next;
		}
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

char	*ft_strjoindels1(char const *s1, char const *s2)
{
	char	*new;

	new = NULL;
	if (s1 && s2)
	{
		if (!(new = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
			return (NULL);
		new = ft_strcpy(new, s1);
		new = ft_strcat(new, s2);
		free((char*)s1);;
		return (new);
	}
	return (NULL);
}

char	*ls_getpath(t_ls *parent, char *path)
{
	char	*tmp;

	if (parent == NULL)
		return (ft_strdup(path));
	if (!(path = ls_getpath(parent->parent, path)))
		return (NULL);
	if (!(is_slash_ended(path)))
	{
		if (!(path = ft_strjoindels1(path, "/")))
			return (NULL);
		if (!(path = ft_strjoindels1(path, parent->pdent->d_name)))
			return (NULL);
		if (!(path = ft_strjoindels1(path, "/")))
			return (NULL);
		return (path);
	}
	if (!(path = ft_strjoindels1(path, parent->pdent->d_name)))
		return (NULL);
	if (!(path = ft_strjoindels1(path, "/")))
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
	print_name(childs);
	h_childs = &childs;
	while (childs && (*childs->pdent->d_name == '.' || (ft_strcmp(childs->pdent->d_name, "..") == 0)))
		childs = childs->next;
	ls_rec(childs, currpath);
	ls_rm(h_childs);
	ls_rec(parent->next, currpath);
	closedir(pdir);
	ft_strdel(&path);
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
		node = ls_new(*pdent, NULL);
		ls_append(&lst, &node);
	}
	lst = ls_mergesort(lst, ls_size(lst));
	print_name(lst);
	/*
	 * reccursivite
	 */
	ls_rec(lst, av[1]);
	closedir(pdir);
	//ls_rm(&lst);
	return (0);
}
