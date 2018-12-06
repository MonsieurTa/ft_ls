/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:04:09 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/06 14:53:04 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "options.h"

/*
** Set l'option opt_name, retourne 0 si tout est ok et -1 si une
** erreur est survenue (parametres invalides etc).
*/

static int			set_opt(t_opts *opts, t_opt_name opt_name)
{
	unsigned int	opt_idx;

	if (opts == NULL || opt_name <= LS_INVALID_OPT || opt_name >= LS_OPT_SIZE)
	{
		return (-1);
	}
	opt_idx = (unsigned int)opt_name;
	opts->mask |= (1 << opt_idx);
	return (0);
}

/*
** Initialise le tableau de char d'opt passe en param.
*/

static void			init_opt_tab(char *opt_tab)
{
	opt_tab[LS_EXTATT] = '@';
	opt_tab[LS_ALL] = 'a';
	opt_tab[LS_DIRASF] = 'd';
	opt_tab[LS_ACL] = 'e';
	opt_tab[LS_NOSORT] = 'f';
	opt_tab[LS_COLOR] = 'G';
	opt_tab[LS_NOOWN] = 'g';
	opt_tab[LS_HUREAD] = 'h';
	opt_tab[LS_LONGF] = 'l';
	opt_tab[LS_NUMID] = 'n';
	opt_tab[LS_NOGRP] = 'o';
	opt_tab[LS_SLASHD] = 'p';
	opt_tab[LS_REC] = 'R';
	opt_tab[LS_REV] = 'r';
	opt_tab[LS_SIZESO] = 'S';
	opt_tab[LS_TIMESO] = 't';
	opt_tab[LS_CREASO] = 'U';
	opt_tab[LS_ACCESO] = 'u';
}

/*
** Retourne l'opt_name de l'option dont le char est passe en parametre
** ou LS_INVALID_OPT si c'est une option invalide.
*/

static t_opt_name	char_to_opt_name(char opt_char)
{
	static char		opt_tab[LS_OPT_SIZE] = {0};
	t_opt_name		idx;

	if (opt_tab[0] == 0)
		init_opt_tab(opt_tab);
	idx = LS_INVALID_OPT + 1;
	while (idx < LS_OPT_SIZE)
	{
		if (opt_tab[idx] == opt_char)
		{
			return (idx);
		}
		++idx;
	}
	return (LS_INVALID_OPT);
}

int					init_opts(int argc, char **argv, t_opts *opts, char *fail)
{
	int			idx;
	int			arg_idx;
	t_opt_name	cur_opt_name;

	if (opts == NULL || fail == NULL)
		return (-1);
	idx = 0;
	while (idx < argc && argv[idx][0] == '-' && argv[idx][1] != '\0')
	{
		arg_idx = 1;
		while (argv[idx][arg_idx] != '\0')
		{
			cur_opt_name = char_to_opt_name(argv[idx][arg_idx]);
			if (cur_opt_name == LS_INVALID_OPT)
			{
				*fail = argv[idx][arg_idx];
				return (-1);
			}
			set_opt(opts, cur_opt_name);
			++arg_idx;
		}
		++idx;
	}
	return (idx);
}

int					get_opt(t_opts *opts, t_opt_name opt_name)
{
	unsigned int	opt_idx;

	if (opts == NULL || opt_name <= LS_INVALID_OPT || opt_name >= LS_OPT_SIZE)
	{
		return (-1);
	}
	opt_idx = (unsigned int)opt_name;
	return ((opts->mask >> opt_idx) & 1);
}
