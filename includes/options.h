/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:09:28 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/17 19:44:31 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H

# include <sys/ioctl.h>
# include "file.h"

typedef struct winsize	t_ws;

/*
** Enum representant la liste des options possibles.
*/
typedef enum	e_opt_name
{
	LS_INVALID_OPT = -1,
	LS_BYLINE = 0,
	LS_ALL,
	LS_BYCLMN,
	LS_STCHTI,
	LS_DIRASF,
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
** Structure contenant des informations sur le format d'affichage.
*/
typedef struct	s_fmt
{
	ssize_t		dir_block_count;
	int			lst_size;
	int			hard_link_max_s;
	int			user_max_s;
	int			group_max_s;
	int			size_max_s;
	int			name_with_deco_max_s;
}				t_fmt;

/*
** Structure representant la liste des options du programme.
** Le pointeur cmp_fun vaut NULL si aucun tri ne doit etre effectue.
*/
typedef struct	s_opts
{
	int		mask;
	t_ws	ws;
	int		tab_w;
	int		has_dir;
	int		has_file;
	int		(*cmp_fun)(t_file *file1, t_file *file2);
	t_fmt	fmt;
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
** Set les options par defauts selon si la sortie standard est
** un terminal ou non.
*/
void			def_opts_for_is_tty(t_opts *opts);

/*
** Set les informations sur la largeur/hauteur du terminal.
*/
void			set_winsize(t_opts *opt);

/*
** Set la largeur d'une tabulation selon les options du programme.
*/
void			set_tab_w(t_opts *opt);

void			init_opt_tab(char *opt_tab);

#endif
