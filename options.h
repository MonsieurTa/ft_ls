/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:09:28 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/06 14:45:46 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H

typedef enum	e_opt_name
{
	LS_INVALID_OPT = -1,
	LS_EXTATT = 0,
	LS_ALL,
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
	LS_REV,
	LS_SIZESO,
	LS_TIMESO,
	LS_CREASO,
	LS_ACCESO,
	LS_OPT_SIZE
}				t_opt_name;

/*
** Structure representant la liste des options du programme.
*/
typedef struct	s_opts
{
	int		mask;
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

#endif
