/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 13:55:13 by wta               #+#    #+#             */
/*   Updated: 2018/12/13 13:48:02 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef	struct dirent	t_dirent;
typedef struct stat		t_stat;

/*
** Structure contenant la liste des champs d'un fichier.
*/
typedef struct	s_fields
{
	char	*rights;
	char	*size;
	char	*color_start_static;
	char	*color_end_static;
	char	*name;
	int		name_len;
}				t_fields;

/*
** t_file est la structure contenant toutes les informations relatives a un
** fichier.
*/
typedef struct	s_file
{
	t_dirent	*pdent;
	t_stat		stat;
	char		*path;
	int			time;
	t_fields	fields;
}				t_file;

#endif
