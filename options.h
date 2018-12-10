/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:09:28 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/10 08:45:00 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H

# include <sys/ioctl.h>
# include "file.h"

typedef struct winsize t_ws;

/*
** Enum representant la liste des options possibles.
*/
typedef enum	e_opt_name
{
	LS_INVALID_OPT = -1,
	LS_EXTATT = 0,
	LS_ALL,
	LS_STCHTI,
	LS_DIRASF,
	LS_ACL,
	LS_NOSORT,
	LS_COLOR,
	LS_NOOWN,
	LS_HUREAD,
	LS_LONGF,
	LS_NUMID,
	LS_NOGRP,
	LS_SLASHD,
	LS_REC,
	LS_REVSO,
	LS_SIZESO,
	LS_TIMESO,
	LS_CREATI,
	LS_ACCETI,
	LS_OPT_SIZE
}				t_opt_name;

/*
** Structure representant la liste des options du programme.
** Le pointeur cmp_fun vaut NULL si aucun tri ne doit etre effectue.
*/
typedef struct	s_opts
{
	int		mask;
	t_ws	ws;
	int		(*cmp_fun)(t_file *file1, t_file *file2);
}				t_opts;

/*
** Prend en parametre une liste d'arguments (sans le nom du programme) et
** un pointeur sur structure d'options deja allouee. Retourne le nombre
** d'arguments lus ou -1 si une option illegale est presente (et set
** sa valeur dans fail, toujours different de '\0') ou si
** les parametres sont invalides (ne modifie pas fail).
*/
int				init_opts(int argc, char **argv, t_opts *opts, char *fail);

/*
** Retourne 1 si l'option opt_name a ete set dans opts, 0 si elle ne
** l'est pas et -1 si opt_name ou opts est invalide.
*/
int				get_opt(t_opts *opts, t_opt_name opt_name);

/*
** Set l'option opt_name a new_val, retourne 0 si tout est ok et -1 si une
** erreur est survenue (parametres invalides etc, new_val doit valoir 0 ou 1).
*/
int				set_opt_val(t_opts *opts, t_opt_name opt_name, int new_val);

/*
** Recupere les informations sur la largeur/hauteur du terminal.
*/ 
t_ws			get_winsize(void);
#endif
