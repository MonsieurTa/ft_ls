/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:36:26 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/11 08:46:12 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPARE_UTILS_H
# define COMPARE_UTILS_H

# include "options.h"
# include "ft_ls.h"

/*
** Set le pointeur cmp_fun de opts sur une fonction de comparaison de
** fichier selon les options passees en parametre, ou NULL si les fichiers
** ne doivent pas etre tries.
*/
void	set_cmp_fun(t_opts *opts);

/*
** Fonction de comparaison de deux fichiers par taille inverse, retourne un
** nombre < 0 si file1 < file2, = 0 si file1 = file2, > 0 si file1 > file2.
*/
int		cmp_file_size_rev(t_file *file1, t_file *file2);

/*
** Fonction de comparaison de deux fichiers par
** date de stat change inverse, retourne un
** nombre < 0 si file1 < file2, = 0 si file1 = file2, > 0 si file1 > file2.
*/
int		cmp_file_stch_rev(t_file *file1, t_file *file2);

/*
** Fonction de comparaison de deux fichiers par date de crea inverse, retourne
** un nombre < 0 si file1 < file2, = 0 si file1 = file2, > 0 si file1 > file2.
*/
int		cmp_file_crea_rev(t_file *file1, t_file *file2);

/*
** Fonction de comparaison de deux fichiers par date d'acces inverse, retourne
** un nombre < 0 si file1 < file2, = 0 si file1 = file2, > 0 si file1 > file2.
*/
int		cmp_file_acce_rev(t_file *file1, t_file *file2);

/*
** Fonction de comparaison de deux fichiers par date de modif inverse, retourne
** un nombre < 0 si file1 < file2, = 0 si file1 = file2, > 0 si file1 > file2.
*/
int		cmp_file_time_rev(t_file *file1, t_file *file2);

/*
** Fonction de comparaison de deux fichiers par ordre lexical inverse, retourne
** un nombre < 0 si file1 < file2, = 0 si file1 = file2, > 0 si file1 > file2.
*/
int		cmp_file_lexical_rev(t_file *file1, t_file *file2);

/*
** Fonction de comparaison de deux fichiers par taille, retourne un
** nombre < 0 si file1 < file2, = 0 si file1 = file2, > 0 si file1 > file2.
*/
int		cmp_file_size(t_file *file1, t_file *file2);

/*
** Fonction de comparaison de deux fichiers par date de stat change, retourne
** un nombre < 0 si file1 < file2, = 0 si file1 = file2, > 0 si file1 > file2.
*/
int		cmp_file_stch(t_file *file1, t_file *file2);

/*
** Fonction de comparaison de deux fichiers par date de crea, retourne un
** nombre < 0 si file1 < file2, = 0 si file1 = file2, > 0 si file1 > file2.
*/
int		cmp_file_crea(t_file *file1, t_file *file2);

/*
** Fonction de comparaison de deux fichiers par date d'acces, retourne un
** nombre < 0 si file1 < file2, = 0 si file1 = file2, > 0 si file1 > file2.
*/
int		cmp_file_acce(t_file *file1, t_file *file2);

/*
** Fonction de comparaison de deux fichiers par date de modif, retourne un
** nombre < 0 si file1 < file2, = 0 si file1 = file2, > 0 si file1 > file2.
*/
int		cmp_file_time(t_file *file1, t_file *file2);

/*
** Fonction de comparaison de deux fichiers par ordre lexical, retourne un
** nombre < 0 si file1 < file2, = 0 si file1 = file2, > 0 si file1 > file2.
*/
int		cmp_file_lexical(t_file *file1, t_file *file2);

/*
** Retourne 0 si time1 = time2, < 0 si time1 < time2, > 0 si time1 > time2.
*/
int		compare_timespec(struct timespec *time1, struct timespec *time2);

#endif
