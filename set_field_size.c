/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_field_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 09:23:58 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/10 11:00:55 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "options.h"
#include "file.h"

static char		*size_to_huread(off_t f_size)
{
	static char		size_letter[] = "BKMGTP";
	int				idx;
	off_t			old_size;
	double			decimal;

	old_size = f_size;
	idx = 0;
	while (f_size >= 1000 && size_letter[idx + 1] != '\0')
	{
		old_size = f_size;
		f_size /= 1024;
		++idx;
	}
	decimal = (old_size / 1024) + 0.05;
	//temporairement parce que je veux me souvenir de ce que je veux faire.
	f_size + "." + (decimal * 10) % 10 + size_letter[idx];
}

int				set_field_size(t_opts *opts, t_file *file, char **field)
{
	if (opts == NULL || file == NULL || field == NULL)
	{
		if (field != NULL)
			*field = NULL;
		return (0);
	}
	if (get_opt(opts, LS_HUREAD) == 1)
		*field = size_to_huread(file->pdent->st_size);
	else
		*field = ft_offtoa(file->pdent->st_size);
	if (*field == NULL)
		return (0);
	else
		return (ft_strlen(*field));
}
