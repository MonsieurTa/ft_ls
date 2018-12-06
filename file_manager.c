/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:48:29 by wta               #+#    #+#             */
/*   Updated: 2018/12/06 18:03:52 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lst_ls	*link_file(char *path)
{
	t_lst_ls	*lst;
	t_file		*file;
	DIR			*pdir;

	pdir = NULL;
	if ((pdir = opendir(path)) == NULL)
		return (NULL);
	file = NULL;
	lst = NULL;
	while ((file = ls_newfile(pdir, path)) != NULL)
		lst_append(&lst, lst_newnode(file));
	closedir(pdir);
	return (lst);
}
