/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 09:06:36 by wta               #+#    #+#             */
/*   Updated: 2018/12/10 09:24:14 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"
#include "libft/includes/libft.h"

int		is_curr_or_parent(t_dirent *pdent)
{
	if (pdent)
	{
		if (ft_strcmp(pdent->d_name, ".") == 0)
			return (1);
		if (ft_strcmp(pdent->d_name, "..") == 0)
			return (1);
	}
	return (0);
}
