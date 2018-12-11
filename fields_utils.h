/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:46:19 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/11 13:09:38 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIELDS_UTILS_H
# define FIELDS_UTILS_H

# include "ft_ls.h"
# include "file.h"
# include "options.h"

/*
** Initialise les fields de chaque fichiers de lst et le fmt pour un
** affichage minimal. Retourne -1 en cas d'erreur et 0 en cas de succes.
*/
int		init_minimum_fields_and_fmt(t_opts *opts, t_lst_ls *lst, t_fmt *fmt);

/*
** Free les fields de chaque fichier de lst qui ont ete alloues pour
** un affichage minimal.
*/
void	delete_minimum_fields(t_lst_ls *lst);

#endif
