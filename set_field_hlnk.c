/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_field_hlnk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 09:30:44 by wta               #+#    #+#             */
/*   Updated: 2018/12/12 09:55:30 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"
#include "options.h"
#include "file.h"
#include "set_field.h"

nlink_t	len_nlink(nlink_t st_nlink)
{
	nlink_t	len;

	len = (st_nlink == 0) ? 1 : 0;
	while (st_nlink)
	{
		st_nlink /= 10;
		len++;
	}
	return (len);
}

int		set_field_nlink(t_opts *opts, t_file *file, char **field)
{
	if (opts == NULL || file == NULL || field == NULL)
	{
		if (field != NULL)
			*field = NULL;
		return (0);
	}
	else
		if ((*field = ft_itoa_u((unsigned int)file->stat.st_nlink)) != NULL)
			return (ft_strlen(*field));
	return (0);
}
