/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_field_date.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:31:03 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/15 09:48:34 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "libft/includes/libft.h"
#include "options.h"
#include "file.h"

static char		*get_date_from_infos(char *ctime_date, char *year_str)
{
	char	*result;
	int		date_size;
	int		year_size;

	date_size = 7;
	if (year_str != NULL)
		date_size += (year_size = (ft_strlen(year_str) - 1));
	else
		date_size += 5;
	if ((result = (char *)malloc(date_size + 1)) == NULL)
		return (NULL);
	ft_memcpy(result, ctime_date + 4, 3);
	result[3] = ' ';
	ft_memcpy(result + 4, ctime_date + 8, 2);
	result[6] = ' ';
	if (year_str != NULL)
		ft_memcpy(result + 7, year_str, year_size);
	else
		ft_memcpy(result + 7, ctime_date + 11, 5);
	result[date_size] = '\0';
	return (result);
}

static char		*get_date_from_timestamp(time_t timestamp, char use_year)
{
	char	*result;
	char	*ctime_date;
	char	*year_str;

	if ((ctime_date = ctime(&timestamp)) == NULL)
		return (NULL);
	if (use_year == 1)
		year_str = ft_strrchr(ctime_date, ' ');
	else
		year_str = NULL;
	if ((result = get_date_from_infos(ctime_date, year_str)) == NULL)
	{
		free(ctime_date);
		return (NULL);
	}
	else
	{
		return (result);
	}
}

#ifdef _DARWIN_FEATURE_64_BIT_INODE

static time_t	get_time_to_use_from_file(t_opts *opts, t_file *file)
{
	if (get_opt(opts, LS_ACCETI) == 1)
		return (file->stat.st_atimespec.tv_sec);
	else if (get_opt(opts, LS_CREATI) == 1)
		return (file->stat.st_birthtimespec.tv_sec);
	else if (get_opt(opts, LS_STCHTI) == 1)
		return (file->stat.st_ctimespec.tv_sec);
	else
		return (file->stat.st_mtimespec.tv_sec);
}

#else

static time_t	get_time_to_use_from_file(t_opts *opts, t_file *file)
{
	if (get_opt(opts, LS_ACCETI) == 1)
		return (file->stat.st_atimespec.tv_sec);
	else if (get_opt(opts, LS_CREATI) == 1)
		return (file->stat.st_ctimespec.tv_sec);
	else if (get_opt(opts, LS_STCHTI) == 1)
		return (file->stat.st_ctimespec.tv_sec);
	else
		return (file->stat.st_mtimespec.tv_sec);
}

#endif

int				set_field_date(t_opts *opts, t_file *file, char **field)
{
	time_t	time_to_use;
	time_t	cur_time;

	if (opts == NULL || file == NULL || field == NULL)
	{
		if (field != NULL)
			*field = NULL;
		return (0);
	}
	time_to_use = get_time_to_use_from_file(opts, file);
	if ((cur_time = time(NULL)) == (time_t)-1)
	{
		*field = NULL;
		return (0);
	}
	if (time_to_use > cur_time || time_to_use <= (cur_time - 15778458))
		*field = get_date_from_timestamp(time_to_use, 1);
	else
		*field = get_date_from_timestamp(time_to_use, 0);
	return (*field == NULL ? 0 : ft_strlen(*field));
}
