/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:12:47 by wta               #+#    #+#             */
/*   Updated: 2018/12/19 14:01:09 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "file.h"
#include "options.h"
#include "fields_utils.h"

t_lst_ls	*lst_newnode(t_file *file)
{
	t_lst_ls	*node;

	if ((node = ft_memalloc(sizeof(t_lst_ls))) == NULL)
		return (NULL);
	node->file = file;
	node->next = NULL;
	return (node);
}

t_dirent	*get_dent(t_opts *opts, DIR *pdir)
{
	t_dirent	*tmp;

	if (get_opt(opts, LS_ALL) == 1)
	{
		if ((tmp = readdir(pdir)) == NULL)
			return (NULL);
	}
	else
		while ((tmp = readdir(pdir)) != NULL)
			if (is_curr_or_parent(tmp->d_name) == 0 && *tmp->d_name != '.')
				break ;
	return (tmp);
}

t_file		*lst_newfile(DIR *pdir, char *path, t_opts *opts)
{
	t_dirent	*tmp;
	t_file		*file;

	file = NULL;
	if ((tmp = get_dent(opts, pdir)) != NULL)
	{
		if ((file = ft_memalloc(sizeof(t_file))) != NULL)
		{
			if ((file->name = ft_strdup(tmp->d_name)) != NULL)
			{
				if ((file->path = get_new_path(path, file->name))
						!= NULL && init_file_infs(file, opts) == 0)
					return (file);
				free(file->path);
			}
			free(file->name);
			free(file);
		}
	}
	return (NULL);
}

void		lst_append(t_lst_ls **head, t_lst_ls **tail, t_lst_ls *node)
{
	t_lst_ls	*tmp;

	tmp = NULL;
	if (*tail != NULL && node != NULL)
	{
		(*tail)->next = node;
		*tail = node;
		node->next = NULL;
	}
	else if (*head && node)
	{
		(*head)->next = node;
		*tail = node;
		node->next = NULL;
	}
	else if (node)
	{
		*head = node;
		(*head)->next = NULL;
	}
}

void		lst_rm(t_lst_ls *lst, t_opts *opts)
{
	t_lst_ls	*tmp;
	int			all_fileds_are_init;

	all_fileds_are_init = get_opt(opts, LS_LONGF);
	tmp = NULL;
	if (lst)
	{
		while (lst)
		{
			tmp = lst;
			lst = lst->next;
			if (all_fileds_are_init == 1)
				delete_all_fields(tmp->file);
			else
				delete_minimum_fields(tmp->file);
			free(tmp->file->name);
			free(tmp->file->path);
			free(tmp->file);
			free(tmp);
		}
	}
}
