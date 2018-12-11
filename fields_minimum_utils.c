/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields_minimum_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:30:12 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/11 15:08:38 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "set_field.h"

/*
** Init a null les fields utilises pour l'affichage minimal.
*/

static void		null_init_minimum_fields(t_file *file)
{
	file->fields.name = NULL;
}

/*
** Free tous les fields alloues dans les lst_size premiers fichier de la
** liste de fichier pour l'affichage minimal.
*/

static void		abort_init_minimum_fields(t_lst_ls *lst, int lst_size)
{
	while (lst != NULL && lst_size != 0)
	{
		free(lst->file->fields.name);
		lst = lst->next;
		--lst_size;
	}
}

int				init_minimum_fields_and_fmt(t_opts *opts, t_lst_ls *lst,
		t_fmt *fmt)
{
	t_lst_ls	*lst_head;
	int			tmp_size;

	lst_head = lst;
	fmt->name_max_s = 0;
	fmt->lst_size = 0;
	while (lst != NULL)
	{
		null_init_minimum_fields(lst->file);
		tmp_size = set_field_name(opts, lst->file, &(lst->file->fields.name));
		if (lst->file->fields.name == NULL)
		{
			abort_init_minimum_fields(lst_head, fmt->lst_size + 1);
			return (-1);
		}
		if (tmp_size > fmt->name_max_s)
			fmt->name_max_s = tmp_size;
		lst = lst->next;
		++(fmt->lst_size);
	}
	return (0);
}

void			delete_minimum_fields(t_lst_ls *lst)
{
	abort_init_minimum_fields(lst, -1);
}
