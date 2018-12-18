/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 12:25:17 by wta               #+#    #+#             */
/*   Updated: 2018/12/17 16:13:00 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

void	*print_error(char *path, char print_name, t_stat *st_stat);
int		print_usage(char *cmd, char c);

#endif
