/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields_all_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:09:09 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/13 12:52:13 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "set_field.h"
#include "fields_utils.h"

/*
** Init a null les fields utilises pour l'affichage complet.
*/

static void		null_init_all_fields(t_file *file)
{
	file->fields.rights = NULL;
	file->fields.size = NULL;
	file->fields.name = NULL;
}

int				init_all_fields_and_fmt(t_opts *opts, t_file *file)
{
	int			tmp_size;

	null_init_all_fields(file);
	tmp_size = set_field_rights(opts, file, &(file->fields.rights));
	if (file->fields.rights == NULL)
	{
		delete_all_fields(file);
		return (-1);
	}
	if (tmp_size > opts->fmt.rights_max_s)
		opts->fmt.rights_max_s = tmp_size;
	tmp_size = set_field_size(opts, file, &(file->fields.size));
	if (file->fields.size == NULL)
	{
		delete_all_fields(file);
		return (-1);
	}
	if (tmp_size > opts->fmt.size_max_s)
		opts->fmt.size_max_s = tmp_size;
	set_field_color_start_static(opts, file, &(file->fields.color_start_static));
	if (file->fields.color_start_static == NULL)
	{
		delete_all_fields(file);
		return (-1);
	}
	set_field_color_end_static(opts, file, &(file->fields.color_end_static));
	if (file->fields.color_end_static == NULL)
	{
		delete_all_fields(file);
		return (-1);
	}
	tmp_size = set_field_name(opts, file, &(file->fields.name));
	if (file->fields.name == NULL)
	{
		delete_all_fields(file);
		return (-1);
	}
	if (tmp_size > opts->fmt.name_max_s)
		opts->fmt.name_max_s = tmp_size;
	++(opts->fmt.lst_size);
	return (0);
}

void			delete_all_fields(t_file *file)
{
	free(file->fields.rights);
	free(file->fields.size);
	free(file->fields.name);
}
