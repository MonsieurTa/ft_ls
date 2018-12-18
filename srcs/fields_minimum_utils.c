/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields_minimum_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:30:12 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/18 12:00:24 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "set_field.h"
#include "fields_utils.h"

/*
** Init a null les fields utilises pour l'affichage minimal.
*/

static void		null_init_minimum_fields(t_file *file)
{
	file->fields.name_deco = NULL;
}

int				init_minimum_fields_and_fmt(t_opts *opts, t_file *file)
{
	null_init_minimum_fields(file);
	set_field_color_start_static(opts, file,
			&(file->fields.color_start_static));
	set_field_color_end_static(opts, file, &(file->fields.color_end_static));
	file->fields.name_with_deco_len = (opts->has_file == 1) ?
		ft_strlen(file->path) : ft_strlen(file->name);
	file->fields.name_with_deco_len += set_field_name_deco(opts, file,
			&(file->fields.name_deco));
	if (file->fields.color_end_static == NULL
			|| file->fields.color_start_static == NULL
			|| file->fields.name_deco == NULL)
	{
		delete_minimum_fields(file);
		return (-1);
	}
	if (file->fields.name_with_deco_len > opts->fmt.name_with_deco_max_s)
		opts->fmt.name_with_deco_max_s = file->fields.name_with_deco_len;
	++(opts->fmt.lst_size);
	return (0);
}

void			delete_minimum_fields(t_file *file)
{
	free(file->fields.name_deco);
}
