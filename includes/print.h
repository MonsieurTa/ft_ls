/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 05:57:10 by wta               #+#    #+#             */
/*   Updated: 2018/12/15 15:26:11 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "ft_ls.h"

typedef struct	s_col_fmt
{
	int		col_size;
	int		max_col;
	int		max_row;
}				t_col_fmt;

int				print_by_col(t_opts *opts, t_lst_ls *lst);
void			display_selector(char *path, char print_name, t_opts *opts);
int				is_hidden(t_file *file);
int				ft_ceil(float x);

#endif
