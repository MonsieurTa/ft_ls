/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:13:16 by wta               #+#    #+#             */
/*   Updated: 2018/12/11 16:39:44 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_lst_ls	*lst_pop_append(t_lst_ls **lst, t_lst_ls *side)
{
	t_lst_ls	*tmp;

	tmp = side->next;
	lst_append(lst, side);
	side = tmp;
	return (side);
}

static t_lst_ls	*lst_merge(t_lst_ls *left, t_lst_ls *right,
		int (*cmp_fun)(t_file *file1, t_file *file2))
{
	t_lst_ls	*res;
	t_lst_ls	*tmp;

	res = NULL;
	tmp = NULL;
	while (left && right)
	{
		if (cmp_fun(left->file, right->file) >= 0)
			left = lst_pop_append(&res, left);
		else
			right = lst_pop_append(&res, right);
	}
	while (left)
		left = lst_pop_append(&res, left);
	while (right)
		right = lst_pop_append(&res, right);
	return (res);
}

t_lst_ls		*lst_mergesort(t_lst_ls *lst,
		int (*cmp_fun)(t_file *file1, t_file *file2))
{
	t_lst_ls	*left;
	t_lst_ls	*right;
	t_lst_ls	*tmp;
	int			index;

	if (lst->next == NULL)
		return (lst);
	left = NULL;
	right = NULL;
	index = 0;
	while (lst)
	{
		tmp = lst->next;
		if (index % 2 == 0)
			lst = lst_pop_append(&left, lst);
		else
			lst = lst_pop_append(&right, lst);
		lst = tmp;
		index++;
	}
	left = lst_mergesort(left, cmp_fun);
	right = lst_mergesort(right, cmp_fun);
	return (lst_merge(left, right, cmp_fun));
}
