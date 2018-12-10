/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 05:57:10 by wta               #+#    #+#             */
/*   Updated: 2018/12/10 09:33:19 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "options.h"
# include "ft_ls.h"

void		get_fmt(t_fmt *fmt, t_lst_ls *lst, t_opts *opts);
int			is_hidden(t_file *file);

#endif
