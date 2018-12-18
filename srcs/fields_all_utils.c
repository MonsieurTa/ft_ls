/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields_all_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:09:09 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/15 11:36:42 by fwerner          ###   ########.fr       */
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
	file->fields.date = NULL;
	file->fields.name_deco = NULL;
}

static	int		check_field_init(int *field_max_s, char **field,
		int init_field_ret)
{
	if (*field == NULL)
	{
		return (-1);
	}
	else if (field_max_s != NULL)
	{
		if (init_field_ret > *field_max_s)
		{
			*field_max_s = init_field_ret;
		}
	}
	return (0);
}

static int		init_simple_fields(t_opts *opts, t_file *file)
{
	int			err_nb;

	err_nb = 0;
	err_nb += check_field_init(NULL, &(file->fields.rights),
			set_field_rights(opts, file, &(file->fields.rights)));
	err_nb += check_field_init(&(opts->fmt.hard_link_max_s),
			&(file->fields.hard_link),
			set_field_nlink(opts, file, &(file->fields.hard_link)));
	err_nb += check_field_init(&(opts->fmt.user_max_s), &(file->fields.user),
			set_field_uid(opts, file, &(file->fields.user)));
	err_nb += check_field_init(&(opts->fmt.group_max_s), &(file->fields.group),
			set_field_gid(opts, file, &(file->fields.group)));
	err_nb += check_field_init(&(opts->fmt.size_max_s), &(file->fields.size),
			set_field_size(opts, file, &(file->fields.size)));
	err_nb += check_field_init(NULL, &(file->fields.date),
			set_field_date(opts, file, &(file->fields.date)));
	err_nb += check_field_init(NULL, &(file->fields.color_start_static),
			set_field_color_start_static(opts, file,
				&(file->fields.color_start_static)));
	err_nb += check_field_init(NULL, &(file->fields.color_end_static),
			set_field_color_end_static(opts, file,
				&(file->fields.color_end_static)));
	return (err_nb);
}

int				init_all_fields_and_fmt(t_opts *opts, t_file *file)
{
	null_init_all_fields(file);
	if (init_simple_fields(opts, file) < 0)
	{
		delete_all_fields(file);
		return (-1);
	}
	file->fields.name_with_deco_len = ft_strlen(file->pdent->d_name);
	file->fields.name_with_deco_len += set_field_name_deco(opts, file,
			&(file->fields.name_deco));
	if (file->fields.name_deco == NULL)
	{
		delete_all_fields(file);
		return (-1);
	}
	if (file->fields.name_with_deco_len > opts->fmt.name_with_deco_max_s)
		opts->fmt.name_with_deco_max_s = file->fields.name_with_deco_len;
	opts->fmt.dir_block_count += file->stat.st_blocks;
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
	free(file->fields.date);
	free(file->fields.name_deco);
}
