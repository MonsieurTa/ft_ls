/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields_minimum_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:30:12 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/15 12:31:55 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "options.h"
#include "set_field.h"
#include "fields_utils.h"

/*
** Init a null les fields utilises pour l'affichage minimal.
*/

static void		null_init_minimum_fields(t_file *f)
{
	f->fields.name_deco = NULL;
}

int				init_minimum_fields_and_fmt(t_opts *opts, t_file *f)
{
	null_init_minimum_fields(f);
	set_field_color_start_static(opts, f, &(f->fields.color_start_static));
	if (f->fields.color_start_static == NULL)
	{
		delete_minimum_fields(f);
		return (-1);
	}
	set_field_color_end_static(opts, f, &(f->fields.color_end_static));
	if (f->fields.color_end_static == NULL)
	{
		delete_minimum_fields(f);
		return (-1);
	}
	f->fields.name_with_deco_len = ft_strlen(f->pdent->d_name);
	f->fields.name_with_deco_len += set_field_name_deco(opts,
			f, &(f->fields.name_deco));
	if (f->fields.name_deco == NULL)
	{
		delete_minimum_fields(f);
		return (-1);
	}
	if (f->fields.name_with_deco_len > opts->fmt.name_with_deco_max_s)
		opts->fmt.name_with_deco_max_s = f->fields.name_with_deco_len;
	++(opts->fmt.lst_size);
	return (0);
}

void			delete_minimum_fields(t_file *f)
{
	free(f->fields.name_deco);
}
