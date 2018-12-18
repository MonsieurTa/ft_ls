/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 12:25:17 by wta               #+#    #+#             */
/*   Updated: 2018/12/18 14:17:30 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "options.h"

void	*print_error(char *path, char print_name, t_stat *st_stat,
					t_opts *opts);
int		print_usage(char *cmd, char c);

#endif
