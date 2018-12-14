/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_field.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 09:17:47 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/14 10:53:30 by fwerner          ###   ########.fr       */
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
** Set le pointeur sur field a une chaine de caractere representant la
** decoration du nom du fichier passe en parametre selon les options.
** Retourne le nombre de caracteres de field, set field a NULL en cas d'erreur.
*/
int		set_field_name_deco(t_opts *opts, t_file *file, char **field);

/*
** Set le pointeur sur field a une chaine de caractere representant la taille
** du fichier passe en parametre selon les options. Retourne le nombre de
** caracteres de field, set field a NULL en cas d'erreur.
*/
int		set_field_size(t_opts *opts, t_file *file, char **field);

/*
** Set le pointeur sur field a une chaine de caractere representant les droits
** du fichier passe en parametre selon les options. Retourne le nombre de
** caracteres de field, set field a NULL en cas d'erreur.
*/
int		set_field_rights(t_opts *opts, t_file *file, char **field);

/*
** Set le pointeur sur field a une chaine de caractere representant le nombre
** de hard link du fichier passe en parametre selon les options. Retourne
** le nombre de caracteres de field, set field a NULL en cas d'erreur.
*/
int		set_field_nlink(t_opts *opts, t_file *file, char **field);

/*
** Set le pointeur sur field a une chaine de caractere representant l'user
** du fichier passe en parametre selon les options. Retourne le nombre de
** caracteres de field, set field a NULL en cas d'erreur.
*/
int		set_field_uid(t_opts *opts, t_file *file, char **field);

/*
** Set le pointeur sur field a une chaine de caractere representant le group
** du fichier passe en parametre selon les options. Retourne le nombre de
** caracteres de field, set field a NULL en cas d'erreur.
*/
int		set_field_gid(t_opts *opts, t_file *file, char **field);

int		has_xattr(char *filepath);
int		has_acl(char *filepath);

#endif
