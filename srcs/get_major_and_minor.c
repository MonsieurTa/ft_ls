/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_major_and_minor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 12:25:30 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/15 13:02:04 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "file.h"

static void		fill_field(char *field)
{
	int	idx;

	idx = 0;
	while (idx < 3)
	{
		field[idx] = ' ';
		idx++;
	}
	field[idx++] = ',';
	while (idx < 8)
	{
		field[idx] = ' ';
		idx++;
	}
}

static int		get_dev_size(dev_t nb)
{
	int size;

	size = 1;
	while (nb < -9 || nb > 9)
	{
		++size;
		nb /= 10;
	}
	return (size);
}

static void		fill_major(char *field, dev_t st_rdev)
{
	int		len;
	int		i;
	dev_t	maj;

	i = 0;
	maj = major(st_rdev);
	len = get_dev_size(maj);
	while (len && i < 3)
	{
		field[2 - i] = '0' + maj % 10;
		maj /= 10;
		i++;
		len--;
	}
}

static void		fill_minor(char *field, dev_t st_rdev)
{
	int		len;
	int		i;
	dev_t	min;

	i = 0;
	min = minor(st_rdev);
	len = get_dev_size(min);
	while (len && i < 3)
	{
		field[7 - i] = '0' + min % 10;
		min /= 10;
		i++;
		len--;
	}
}

char			*get_major_and_minor(dev_t st_rdev)
{
	char	*field;

	field = NULL;
	if ((field = ft_strnew(8)) != NULL)
	{
		fill_field(field);
		fill_major(field, st_rdev);
		fill_minor(field, st_rdev);
	}
	return (field);
}
