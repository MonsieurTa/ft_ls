/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_rules.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 08:02:04 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/07 11:44:31 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_RULES_H
# define OPTIONS_RULES_H

# include "options.h"

/*
** Modifie la liste des options selon la derniere option qui vient d'etre
** ajoutee, en cas de dependance ou de conflit d'options.
*/
void	apply_rules_for_opt(t_opts *opts, t_opt_name opt_name);

#endif
