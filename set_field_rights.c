/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_field_rights.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:17:25 by wta               #+#    #+#             */
/*   Updated: 2018/12/10 14:08:00 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "options.h"
#include "file.h"

char	get_file_type(t_dirent *pdent)
{
	if (pdent->d_type == DT_BLK)
		return ('b');
	if (pdent->d_type == DT_CHR)
		return ('c');
	if (pdent->d_type == DT_DIR)
		return ('d');
	if (pdent->d_type == DT_FIFO)
		return ('p');
	if (pdent->d_type == DT_LNK)
		return ('l');
	if (pdent->d_type == DT_REG)
		return ('-');
	if (pdent->d_type == DT_SOCK)
		return ('s');
	return ('?');
}

int		set_field_rights(t_opts *opts, t_file *file, char **field)
{
	if (opts == NULL || file == NULL || field == NULL)
	{
		if (field != NULL)
			*field = NULL;
		return (0);
	}
	if ((*field = ft_strnew(11)) != NULL)
	{
		*field[0] = get_file_type(file->pdent);
	}
	return (1);
}
