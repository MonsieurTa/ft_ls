/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:13:16 by wta               #+#    #+#             */
/*   Updated: 2018/12/15 13:01:01 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_lst_ls	*lst_pop_append(t_lst_ls **head,
		t_lst_ls **tail, t_lst_ls *side)
{
	t_lst_ls	*tmp;

	tmp = side->next;
	lst_append(head, tail, side);
	side = tmp;
	return (side);
}

static t_lst_ls	*lst_merge(t_lst_ls *left, t_lst_ls *right,
		int (*cmp_fun)(t_file *file1, t_file *file2))
{
	t_lst_info	res;
	t_lst_ls	*tmp;

	res.head = NULL;
	res.tail = NULL;
	tmp = NULL;
	while (left && right)
	{
		if (cmp_fun(left->file, right->file) >= 0)
			left = lst_pop_append(&res.head, &res.tail, left);
		else
			right = lst_pop_append(&res.head, &res.tail, right);
	}
	while (left)
		left = lst_pop_append(&res.head, &res.tail, left);
	while (right)
		right = lst_pop_append(&res.head, &res.tail, right);
	return (res.head);
}

t_lst_ls		*lst_mergesort(t_lst_ls *lst,
		int (*cmp_fun)(t_file *file1, t_file *file2))
{
	t_lst_info	left;
	t_lst_info	right;
	t_lst_ls	*tmp;
	int			index;

	if (lst->next == NULL)
		return (lst);
	left.head = NULL;
	left.tail = NULL;
	right.head = NULL;
	right.tail = NULL;
	index = 0;
	while (lst)
	{
		tmp = lst->next;
		if (index % 2 == 0)
			lst = lst_pop_append(&left.head, &left.tail, lst);
		else
			lst = lst_pop_append(&right.head, &right.tail, lst);
		lst = tmp;
		index++;
	}
	left.head = lst_mergesort(left.head, cmp_fun);
	right.head = lst_mergesort(right.head, cmp_fun);
	return (lst_merge(left.head, right.head, cmp_fun));
}
