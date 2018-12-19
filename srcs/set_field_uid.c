/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_field_uid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 10:00:58 by wta               #+#    #+#             */
/*   Updated: 2018/12/19 14:04:20 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"
#include "options.h"
#include "file.h"
#include "set_field.h"
#include "pwd.h"

int		set_field_uid(t_opts *opts, t_file *file, char **field)
{
	struct passwd	*pwd;

	pwd = NULL;
	if (opts == NULL || file == NULL || field == NULL)
	{
		if (field != NULL)
			*field = NULL;
		return (0);
	}
	else
	{
		if (get_opt(opts, LS_NOOWN) == 1)
			*field = ft_strdup("");
		else if (get_opt(opts, LS_NUMID) == 1)
			*field = ft_itoa_u((file->stat.st_uid));
		else
		{
			if ((pwd = getpwuid(file->stat.st_uid)) != NULL)
				*field = ft_strdup(pwd->pw_name);
			else
				*field = ft_itoa(file->stat.st_uid);
		}
		return (*field == NULL ? 0 : ft_strlen(*field));
	}
}
