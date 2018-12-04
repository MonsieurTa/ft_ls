/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_ls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 08:37:00 by wta               #+#    #+#             */
/*   Updated: 2018/12/04 09:39:01 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	*ls_new(struct dirent *pdent)
{
	t_ls	*node;

	if (!(node = (t_ls*)malloc(sizeof(t_ls))))
		return (NULL);
	node->next = NULL;
	if (!(node->pdent = ft_memalloc(sizeof(*pdent))))
		return (NULL);
	ft_memcpy(node->pdent, pdent, sizeof(*pdent));
	return (node);
}

void	ls_append(t_ls **lst, t_ls *node)
{
	t_ls	*tmp;

	tmp = NULL;
	if (*lst && node)
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
	else if (node)
		*lst = node;
}

void	ls_rm(t_ls **lst)
{
	t_ls	*tmp;

	tmp = NULL;
	if (*lst)
	{
		while (*lst)
		{
			tmp = *lst;
			*lst = *(lst)->next;
			free(tmp);
		}
	}
}

void	ls_sort(t_ls **lst, int n)
{

}
