/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 05:57:10 by wta               #+#    #+#             */
/*   Updated: 2018/12/12 14:43:37 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "ft_ls.h"

void		display_selector(char *path, char print_name, t_opts *opts);
int			is_hidden(t_file *file);
int			ft_ceil(float x);

#endif