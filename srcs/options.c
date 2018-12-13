/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:04:09 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/11 07:55:34 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "options_rules.h"
#include "options.h"

/*
** Initialise le tableau de char d'opt passe en param.
*/

static void			init_opt_tab(char *opt_tab)
{
	opt_tab[LS_EXTATT] = '@';
	opt_tab[LS_BYLINE] = '1';
	opt_tab[LS_ALL] = 'a';
	opt_tab[LS_BYCLMN] = 'C';
	opt_tab[LS_STCHTI] = 'c';
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
	opt_tab[LS_REVSO] = 'r';
	opt_tab[LS_SIZESO] = 'S';
	opt_tab[LS_TIMESO] = 't';
	opt_tab[LS_CREATI] = 'U';
	opt_tab[LS_ACCETI] = 'u';
}

/*
** Retourne l'opt_name de l'option dont le char est passe en parametre
** ou LS_INVALID_OPT si c'est une option invalide.
*/

static t_opt_name	char2opt(char opt_char)
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

	if ((idx = 0) == 1 || opts == NULL || fail == NULL)
		return (-1);
	while (idx < argc && argv[idx][0] == '-' && argv[idx][1] != '\0')
	{
		if (argv[idx][1] == '-' && argv[idx][2] == '\0')
			return (idx + 1);
		arg_idx = 1;
		while (argv[idx][arg_idx] != '\0')
		{
			if ((cur_opt_name = char2opt(argv[idx][arg_idx])) == LS_INVALID_OPT)
			{
				*fail = argv[idx][arg_idx];
				return (-1);
			}
			set_opt_val(opts, cur_opt_name, 1);
			apply_rules_for_opt(opts, cur_opt_name);
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

int					set_opt_val(t_opts *opts, t_opt_name opt_name, int new_val)
{
	unsigned int	opt_idx;

	if ((new_val != 0 && new_val != 1) || opts == NULL
			|| opt_name <= LS_INVALID_OPT || opt_name >= LS_OPT_SIZE)
	{
		return (-1);
	}
	opt_idx = (unsigned int)opt_name;
	if (new_val == 0)
		opts->mask &= ~(1 << opt_idx);
	else
		opts->mask |= (1 << opt_idx);
	return (0);
}
