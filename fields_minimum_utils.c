/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields_minimum_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:30:12 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/12 09:30:19 by fwerner          ###   ########.fr       */
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
	file->fields.name = NULL;
}

int				init_minimum_fields_and_fmt(t_opts *opts, t_file *file)
{
	int			tmp_size;

	null_init_minimum_fields(file);
	tmp_size = set_field_name(opts, file, &(file->fields.name));
	if (file->fields.name == NULL)
	{
		delete_minimum_fields(file);
		return (-1);
	}
	if (tmp_size > opts->fmt.name_max_s)
		opts->fmt.name_max_s = tmp_size;
	++(opts->fmt.lst_size);
	return (0);
}

void			delete_minimum_fields(t_file *file)
{
	free(file->fields.name);
}
