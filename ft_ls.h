/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 06:23:36 by wta               #+#    #+#             */
/*   Updated: 2018/12/05 04:41:47 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/includes/ft_printf.h"
# include "libft/includes/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <string.h>
# include <dirent.h>

typedef struct	s_ls
{
	struct s_ls		*parent;
	struct s_ls		*next;
	struct dirent	*pdent;
}				t_ls;

typedef struct	s_opt
{
	int				opt;

}				t_opt;

t_ls	*ls_new(struct dirent pdent, t_ls *parent);
int		ls_size(t_ls *lst);
void	ls_append(t_ls **lst, t_ls **node);
void	ls_rm(t_ls **lst);
t_ls	*ls_merge(t_ls *left, t_ls *right);
t_ls	*ls_mergesort(t_ls *lst, int n);

#endif
