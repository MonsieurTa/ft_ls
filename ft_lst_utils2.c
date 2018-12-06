/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:13:16 by wta               #+#    #+#             */
/*   Updated: 2018/12/06 17:42:28 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_lst_ls	*lst_pop_append(t_lst_ls *lst, t_lst_ls *side)
{
	t_lst_ls	*tmp;

	tmp = side->next;
	lst_append(&lst, side);
	side = tmp;
	return (side);
}

static t_lst_ls	*lst_merge(t_lst_ls	*left, t_lst_ls *right)
{
	t_lst_ls	*res;
	t_lst_ls	*tmp;
	char		*s1;
	char		*s2;

	res = NULL;
	tmp = NULL;
	while (left && right)
	{
		s1 = left->file->pdent->d_name;
		s2 = right->file->pdent->d_name;
		if (ft_strcmp(s1, s2) <= 0)
			left = lst_pop_append(res, left);
		else
			right = lst_pop_append(res, right);
	}
	while (left)
		left = lst_pop_append(res, left);
	while (right)
		right = lst_pop_append(res, right);
	return (res);
}

t_lst_ls		*lst_mergesort(t_lst_ls *lst, int len)
{
	t_lst_ls	*left;
	t_lst_ls	*right;
	t_lst_ls	*tmp;
	int			index;

	if (len <= 1)
		return (lst);
	left = NULL;
	right = NULL;
	index = -1;
	while (++index < len)
	{
		tmp = lst->next;
		if (index < len / 2)
			lst_append(&left, lst);
		else
			lst_append(&right, lst);
		lst = tmp;
	}
	left = lst_mergesort(left, lst_size(left));
	right = lst_mergesort(right, lst_size(right));
	return (lst_merge(left, right));
}
