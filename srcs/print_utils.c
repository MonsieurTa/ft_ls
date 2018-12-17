/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 05:52:59 by wta               #+#    #+#             */
/*   Updated: 2018/12/15 11:18:19 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_hidden(t_file *file)
{
	if (file)
	{
		if (*file->pdent->d_name == '.')
			return (1);
	}
	return (0);
}

/*
** Retourne x arrondi a l'entier superieur.
*/

int		ft_ceil(float x)
{
	int	ix;

	ix = (int)x;
	if (x == (float)ix)
		return (ix);
	return (ix + 1);
}
