/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 09:06:36 by wta               #+#    #+#             */
/*   Updated: 2018/12/18 11:59:18 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"
#include "libft/includes/libft.h"

int		is_curr_or_parent(char *name)
{
	if (name)
	{
		if (ft_strcmp(name, ".") == 0)
			return (1);
		if (ft_strcmp(name, "..") == 0)
			return (1);
	}
	return (0);
}
