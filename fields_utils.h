/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:46:19 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/12 09:50:05 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIELDS_UTILS_H
# define FIELDS_UTILS_H

# include "ft_ls.h"
# include "file.h"
# include "options.h"

/*
** Initialise les fields du fichier et maj le fmt pour un affichage minimal.
** Retourne -1 en cas d'erreur et 0 en cas de succes.
*/
int		init_minimum_fields_and_fmt(t_opts *opts, t_file *file);

/*
** Free les fields du fichier qui ont ete alloues pour un affichage minimal.
*/
void	delete_minimum_fields(t_file *file);

/*
** Initialise les fields du fichier et maj le fmt pour un affichage complet.
** Retourne -1 en cas d'erreur et 0 en cas de succes.
*/
int		init_all_fields_and_fmt(t_opts *opts, t_file *file);

/*
** Free les fields du fichier qui ont ete alloues pour un affichage complet.
*/
void	delete_all_fields(t_file *file);

#endif
