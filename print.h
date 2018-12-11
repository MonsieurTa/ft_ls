/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 05:57:10 by wta               #+#    #+#             */
/*   Updated: 2018/12/11 14:33:53 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "ft_ls.h"

void		display_selector(char *path, char *currdir, t_opts *opts);
int			is_hidden(t_file *file);

#endif
