/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 12:22:02 by wta               #+#    #+#             */
/*   Updated: 2018/12/18 14:13:22 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"
#include "libft/includes/ft_printf.h"
#include "error.h"
#include "options.h"
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

static char	*get_filename(char *filepath)
{
	int	len;

	if (filepath)
	{
		len = ft_strlen(filepath);
		while (len >= 0 && filepath[len] != '/')
			len--;
		return (&filepath[len + 1]);
	}
	return ("");
}

void		*print_error(char *path, char print_name, t_stat *st_stat,
						t_opts *opts)
{
	if (st_stat != NULL && ((print_name & 1) == 1))
	{
		ft_putstr(path);
		ft_putstr(":\n");
	}
	if (errno)
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd((print_name & 2) == 2 ? path : get_filename(path), 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putchar_fd('\n', 2);
		errno = 0;
		opts->error = 1;
	}
	return (NULL);
}

int			print_usage(char *cmd, char c)
{
	char	opt_tab[LS_OPT_SIZE];
	int		idx;

	idx = -1;
	init_opt_tab(opt_tab);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: ls [-", 2);
	while (++idx < LS_OPT_SIZE)
		ft_putchar_fd(opt_tab[idx], 2);
	ft_putstr_fd("] [file ...]\n", 2);
	return (1);
}
