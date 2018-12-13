/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_field.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 09:17:47 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/13 14:21:22 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_FIELD_H
# define SET_FIELD_H

# include "options.h"
# include "file.h"

/*
** Set le pointeur sur field a une chaine de caractere representant le debut
** de la couleur du fichier passe en parametre selon les options. Retourne 0,
** n'echoue jamais si les parametres sont valide, sinon retourne NULL.
** *field ne devra pas etre free car pointera sur une string du stack.
*/
int		set_field_color_start_static(t_opts *opts, t_file *file, char **field);

/*
** !! Doit obligatoirement etre appele apres set_field_color_start_static !!
** Set le pointeur sur field a une chaine de caractere representant la fin
** de la couleur du fichier passe en parametre selon les options. Retourne 0,
** n'echoue jamais si les parametres sont valide, sinon retourne NULL.
** *field ne devra pas etre free car pointera sur une string du stack.
*/
int		set_field_color_end_static(t_opts *opts, t_file *file, char **field);

/*
** Set le pointeur sur field a une chaine de caractere representant le nom
** du fichier passe en parametre selon les options. Retourne le nombre de
** caracteres de field, set field a NULL en cas d'erreur.
*/
int		set_field_name(t_opts *opts, t_file *file, char **field);

/*
** Set le pointeur sur field a une chaine de caractere representant la cible du
** du symlink passe en parametre, chaine vide si file n'est pas un symlink.
** Retourne le nombre de caracteres de field, set field a NULL en cas d'erreur.
*/
int		set_field_symlink(t_opts *opts, t_file *file, char **field);

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
