/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_field.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 09:17:47 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/11 09:13:20 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_FIELD_H
# define SET_FIELD_H

# include "options.h"
# include "file.h"

/*
** Set le pointeur sur field a une chaine de caractere representant le nom
** du fichier passe en parametre selon les options. Retourne le nombre de
** caracteres de field, set field a NULL en cas d'erreur.
*/
int		set_field_name(t_opts *opts, t_file *file, char **field);

/*
** Set le pointeur sur field a une chaine de caractere representant la taille
** du fichier passe en parametre selon les options. Retourne le nombre de
** caracteres de field, set field a NULL en cas d'erreur.
*/
int		set_field_size(t_opts *opts, t_file *file, char **field);

int		set_field_rights(t_opts *opts, t_file *file, char **field);

int		has_xattr(char *filepath);
int		has_acl(char *filepath);

#endif
