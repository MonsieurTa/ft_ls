/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields_all_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:09:09 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/11 15:21:28 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "set_field.h"

/*
** Init a null les fields utilises pour l'affichage complet.
*/

static void		null_init_all_fields(t_file *file)
{
	file->fields.rights = NULL;
	file->fields.size = NULL;
	file->fields.name = NULL;
}

/*
** Free tous les fields alloues dans les lst_size premiers fichier de la
** liste de fichier pour l'affichage complet.
*/

static void		abort_init_all_fields(t_lst_ls *lst, int lst_size)
{
	while (lst != NULL && lst_size != 0)
	{
		free(lst->file->fields.rights);
		free(lst->file->fields.size);
		free(lst->file->fields.name);
		lst = lst->next;
		--lst_size;
	}
}

int				init_all_fields_and_fmt(t_opts *opts, t_lst_ls *lst,
		t_fmt *fmt)
{
	t_lst_ls	*lst_head;
	int			tmp_size;

	lst_head = lst;
	fmt->rights_max_s = 0;
	fmt->size_max_s = 0;
	fmt->name_max_s = 0;
	fmt->lst_size = 0;
	while (lst != NULL)
	{
		null_init_all_fields(lst->file);
		tmp_size = set_field_rights(opts, lst->file, &(lst->file->fields.rights));
		if (lst->file->fields.rights == NULL)
		{
			abort_init_all_fields(lst_head, fmt->lst_size + 1);
			return (-1);
		}
		if (tmp_size > fmt->rights_max_s)
			fmt->rights_max_s = tmp_size;
		tmp_size = set_field_size(opts, lst->file, &(lst->file->fields.size));
		if (lst->file->fields.size == NULL)
		{
			abort_init_all_fields(lst_head, fmt->lst_size + 1);
			return (-1);
		}
		if (tmp_size > fmt->size_max_s)
			fmt->size_max_s = tmp_size;
		tmp_size = set_field_name(opts, lst->file, &(lst->file->fields.name));
		if (lst->file->fields.name == NULL)
		{
			abort_init_all_fields(lst_head, fmt->lst_size + 1);
			return (-1);
		}
		if (tmp_size > fmt->name_max_s)
			fmt->name_max_s = tmp_size;
		lst = lst->next;
		++(fmt->lst_size);
	}
	return (0);
}

void			delete_all_fields(t_lst_ls *lst)
{
	abort_init_all_fields(lst, -1);
}
