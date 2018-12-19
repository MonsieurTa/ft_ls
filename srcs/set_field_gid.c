/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_field_gid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 10:26:28 by wta               #+#    #+#             */
/*   Updated: 2018/12/19 14:22:19 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"
#include "options.h"
#include "file.h"
#include "set_field.h"
#include "grp.h"

int		set_field_gid(t_opts *opts, t_file *file, char **field)
{
	struct group	*grp;

	grp = NULL;
	if (opts == NULL || file == NULL || field == NULL)
	{
		if (field != NULL)
			*field = NULL;
		return (0);
	}
	else
	{
		if (get_opt(opts, LS_NOGRP) == 1)
			*field = ft_strdup("");
		else if (get_opt(opts, LS_NUMID) == 1)
			*field = ft_itoa_u((file->stat.st_gid));
		else
		{
			if ((grp = getgrgid(file->stat.st_gid)) != NULL)
				*field = ft_strdup(grp->gr_name);
			else
				*field = ft_itoa(file->stat.st_gid);
		}
		return (*field == NULL ? 0 : ft_strlen(*field));
	}
}
