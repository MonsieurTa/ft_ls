/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:36:26 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/07 16:14:09 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPARE_UTILS_H
# define COMPARE_UTILS_H

# include "options.h"
# include "ft_ls.h"

/*
** Retourne un pointeur sur fonction pour effectuer les comparaisons de
** fichier selon les options passees en parametre.
** Fonction prefixee par g_ car la norminette est bugee et croit que c'est
** une variable.
*/
int		(*g_init_cmp_fun(t_opts *opts))(t_file *file1, t_file *file2);

#endif
