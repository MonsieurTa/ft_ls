/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:12:47 by wta               #+#    #+#             */
/*   Updated: 2018/12/08 07:54:18 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lst_ls	*lst_newnode(t_file *file)
{
	t_lst_ls	*node;

	if ((node = ft_memalloc(sizeof(t_lst_ls))) == NULL)
		return (NULL);
	node->file = file;
	node->next = NULL;
	return (node);
}

t_file		*ls_newfile(DIR *pdir, char *path)
{
	t_dirent	*tmp;
	t_file		*file;

	file = NULL;
	if ((file = ft_memalloc(sizeof(t_file))) != NULL)
	{
		if ((tmp = readdir(pdir)) != NULL)
		{
			if ((file->pdent = ft_memalloc(tmp->d_reclen)) != NULL)
			{
				ft_memcpy(file->pdent, tmp, tmp->d_reclen);
				if ((stat(path, &(file->stat)) == 0))
					if ((file->path = get_new_path(path, file->pdent->d_name))
							!= NULL)
						return (file);
			}
			free(file->pdent);
		}
		free(file);
	}
	return (NULL);
}

void		lst_append(t_lst_ls **lst, t_lst_ls *node)
{
	t_lst_ls	*tmp;

	tmp = NULL;
	if (*lst && node)
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
		node->next = NULL;
	}
	else if (node)
	{
		*lst = node;
		(*lst)->next = NULL;
	}
}

void		lst_rm(t_lst_ls *lst)
{
	t_lst_ls	*tmp;

	tmp = NULL;
	if (lst)
	{
		while (lst)
		{
			tmp = lst;
			lst = lst->next;
			free(tmp->file->pdent);
			free(tmp->file->path);
			free(tmp->file);
			free(tmp);
		}
	}
}

int			lst_size(t_lst_ls *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
