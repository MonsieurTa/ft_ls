/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_timespec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 13:22:35 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/08 13:37:39 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "compare_utils.h"

int		compare_timespec(struct timespec *time1, struct timespec *time2)
{
	if (time1->tv_sec > time2->tv_sec)
		return (1);
	else if (time1->tv_sec < time2->tv_sec)
		return (-1);
	else
	{
		if (time1->tv_nsec > time2->tv_nsec)
			return (1);
		else if (time1->tv_nsec < time2->tv_nsec)
			return (-1);
		else
			return (0);
	}
}
