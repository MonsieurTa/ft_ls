/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_file_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 13:40:50 by wta               #+#    #+#             */
/*   Updated: 2018/12/15 13:46:45 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_dirpath(char *filepath, char *filename)
{
	int		len;

	if (filepath)
	{
		len = ft_strlen(filepath);
		while (len >= 0 && filepath[len] != '/')
			len--;
		if (len < 0)
			return (ft_strdup("."));
		else
			return (ft_strndup(filepath, len));
	}
	free(filename);
	return (NULL);
}

char	*get_filename(char *filepath)
{
	int		len;

	if (filepath)
	{
		len = ft_strlen(filepath);
		while (len >= 0 && filepath[len] != '/')
			len--;
		if (len < 0)
			return (ft_strdup(filepath));
		else
			return (ft_strdup(&filepath[len + 1]));
	}
	return (NULL);
}
