/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 12:29:48 by wta               #+#    #+#             */
/*   Updated: 2018/12/15 12:31:04 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "options.h"
#include "file.h"

void	init_fmt(t_opts *opts)
{
	opts->fmt.dir_block_count = 0;
	opts->fmt.hard_link_max_s = 0;
	opts->fmt.user_max_s = 0;
	opts->fmt.group_max_s = 0;
	opts->fmt.size_max_s = 0;
	opts->fmt.name_with_deco_max_s = 0;
	opts->fmt.lst_size = 0;
}

int		init_file_infs(t_file *file, t_opts *opts)
{
	int		fun_ret;

	fun_ret = lstat(file->path, &(file->stat));
	if (fun_ret == 0)
	{
		if (get_opt(opts, LS_LONGF) == 1)
			fun_ret = init_all_fields_and_fmt(opts, file);
		else
			fun_ret = init_minimum_fields_and_fmt(opts, file);
		if (fun_ret == 0)
			return (0);
	}
	return (-1);
}
