/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 06:53:21 by wta               #+#    #+#             */
/*   Updated: 2018/12/18 11:20:49 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		*ft_strjoinpath(char const *s1, char const *s2)
{
	char	*new;
	int		index;

	new = NULL;
	if (s1 && s2)
	{
		if (!(new = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 2)))
			return (NULL);
		index = 0;
		while (s1[index] != '\0')
		{
			new[index] = s1[index];
			index++;
		}
		new[index] = '/';
		new[index + 1] = '\0';
		new = ft_strcat(new, s2);
		return (new);
	}
	return (NULL);
}

char			*get_new_path(char *path, char *name)
{
	if (path != NULL && name != NULL)
	{
		if (ft_strcmp(name, ".") == 0)
			return (ft_strdup(path));
		return (ft_strjoinpath(path, name));
	}
	return (NULL);
}
