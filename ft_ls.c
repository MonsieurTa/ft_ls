/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 09:56:50 by wta               #+#    #+#             */
/*   Updated: 2018/12/05 08:25:21 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	*ls_new(struct dirent pdent, t_ls *parent)
{
	t_ls	*node;

	if (!(node = (t_ls*)malloc(sizeof(t_ls))))
		return (NULL);
	node->next = NULL;
	node->parent = parent;
	if (!(node->pdent = (struct dirent*)malloc(pdent.d_reclen)))
		return (NULL);
	ft_memcpy(node->pdent, &pdent, pdent.d_reclen);
	return (node);
}

void	ls_append(t_ls **lst, t_ls **node)
{
	t_ls	*tmp;

	tmp = NULL;
	if (*lst && *node)
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *node;
		(*node)->next = NULL;
	}
	else if (*node)
	{
		*lst = *node;
		(*node)->next = NULL;
	}
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
			*lst = (*lst)->next;
			free(tmp->pdent);
			tmp->pdent = NULL;
			free(tmp);
			tmp = NULL;
		}
	}
}

int		ls_size(t_ls *lst)
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

t_ls	*ls_pop_append(t_ls **lst, t_ls **side)
{
	t_ls	*tmp;

	tmp = (*side)->next;
	ls_append(lst, side);
	*side = tmp;
	return (*side);
}

t_ls	*ls_merge(t_ls *left, t_ls *right)
{
	t_ls	*res;
	t_ls	*tmp;
	char	*s1;
	char	*s2;

	res = NULL;
	tmp = NULL;
	while (left && right)
	{
		s1 = left->pdent->d_name;
		s2 = right->pdent->d_name;
		if (ft_strcmp(s1, s2) <= 0)
			left = ls_pop_append(&res, &left);
		else
			right = ls_pop_append(&res, &right);
	}
	while (left)
		left = ls_pop_append(&res, &left);
	while (right)
		right = ls_pop_append(&res, &right);
	return (res);
}

t_ls	*ls_mergesort(t_ls *lst, int n)
{
	t_ls	*left;
	t_ls	*right;
	t_ls	*tmp;
	int		index;

	if (n <= 1)
		return (lst);
	left = NULL;
	right = NULL;
	index = -1;
	while (++index < n)
	{
		tmp = lst->next;
		if (index < n / 2)
			ls_append(&left, &lst);
		else
			ls_append(&right, &lst);
		lst = tmp;
	}
	left = ls_mergesort(left, ls_size(left));
	right = ls_mergesort(right, ls_size(right));
	return (ls_merge(left, right));
}
