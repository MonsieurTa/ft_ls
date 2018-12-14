/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_field_color_start_static.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 12:48:00 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/13 13:11:56 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "options.h"
#include "file.h"
#include "set_field.h"

int		set_field_color_end_static(t_opts *opts, t_file *file, char **field)
{
	if (opts == NULL || file == NULL || field == NULL)
	{
		if (field != NULL)
			*field = NULL;
		return (0);
	}
	if (get_opt(opts, LS_COLOR) == 1)
	{
		if ((file->fields.color_start_static)[0] == '\0')
			*field = "";
		else
			*field = "\033[0m";
	}
	else
	{
		*field = "";
	}
	return (0);
}
