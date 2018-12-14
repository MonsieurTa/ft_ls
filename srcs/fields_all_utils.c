/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields_all_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:09:09 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/14 10:53:50 by fwerner          ###   ########.fr       */
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
	file->fields.hard_link = NULL;
	file->fields.user = NULL;
	file->fields.group = NULL;
	file->fields.size = NULL;
	file->fields.name_deco = NULL;
}

int				init_all_fields_and_fmt(t_opts *opts, t_file *file)
{
	int			tmp_size;

	null_init_all_fields(file);
	set_field_rights(opts, file, &(file->fields.rights));
	if (file->fields.rights == NULL)
	{
		delete_all_fields(file);
		return (-1);
	}
	tmp_size = set_field_nlink(opts, file, &(file->fields.hard_link));
	if (file->fields.hard_link == NULL)
	{
		delete_all_fields(file);
		return (-1);
	}
	if (tmp_size > opts->fmt.hard_link_max_s)
		opts->fmt.hard_link_max_s = tmp_size;
	tmp_size = set_field_uid(opts, file, &(file->fields.user));
	if (file->fields.user == NULL)
	{
		delete_all_fields(file);
		return (-1);
	}
	if (tmp_size > opts->fmt.user_max_s)
		opts->fmt.user_max_s = tmp_size;
	tmp_size = set_field_gid(opts, file, &(file->fields.group));
	if (file->fields.group == NULL)
	{
		delete_all_fields(file);
		return (-1);
	}
	if (tmp_size > opts->fmt.group_max_s)
		opts->fmt.group_max_s = tmp_size;
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
	file->fields.name_with_deco_len = ft_strlen(file->pdent->d_name);
	file->fields.name_with_deco_len += set_field_name_deco(opts, file, &(file->fields.name_deco));
	if (file->fields.name_deco == NULL)
	{
		delete_all_fields(file);
		return (-1);
	}
	if (file->fields.name_with_deco_len > opts->fmt.name_with_deco_max_s)
		opts->fmt.name_with_deco_max_s = file->fields.name_with_deco_len;
	++(opts->fmt.lst_size);
	return (0);
}

void			delete_all_fields(t_file *file)
{
	free(file->fields.rights);
	free(file->fields.hard_link);
	free(file->fields.user);
	free(file->fields.group);
	free(file->fields.size);
	free(file->fields.name_deco);
}
