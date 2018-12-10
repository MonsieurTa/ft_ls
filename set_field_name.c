/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_field_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 09:05:00 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/10 09:17:36 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "options.h"
#include "file.h"

int		set_field_name(t_opts *opts, t_file *file, char **field)
{
	if (opts == NULL || file == NULL || field == NULL)
	{
		if (field != NULL)
			*field = NULL;
		return (0);
	}
	if (get_opt(opts, LS_SLASHD) == 1 && file->pdent->d_type == DT_DIR)
	{
		*field = ft_strjoin(file->pdent->d_name, "/");
		return (ft_strlen(file->pdent->d_name) + 1);
	}
	else
	{
		*field = ft_strdup(file->pdent->d_name);
		return (ft_strlen(file->pdent->d_name));
	}
}
