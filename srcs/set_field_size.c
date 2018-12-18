/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_field_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwerner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 09:23:58 by fwerner           #+#    #+#             */
/*   Updated: 2018/12/15 12:34:22 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "options.h"
#include "file.h"
#include "set_field.h"

/*
** Attention, code degueulasse pas loin, vaut mieux pas lire.
*/

/*
** Retourne le nombre de chiffres dans le numero de type off_t.
*/

static int		get_off_num_size(off_t nb)
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

/*
** Convertis le nombre de taille nb_len de type off_t en ASCII
** et le place dans la chaine de caractere passee en parametre.
** Tous les parametres doivent etre valides.
*/

static void		offtoa_inside(off_t nb, int nb_len, char *inside)
{
	int		idx;

	if (nb < 0)
	{
		inside[0] = '-';
		--nb_len;
	}
	idx = 0;
	while (nb < -9 || nb > 9)
	{
		inside[nb_len - idx - 1] = '0' + ((nb < 0 ? -nb : nb) % 10);
		nb /= 10;
		++idx;
	}
	inside[nb_len - idx - 1] = '0' + ((nb < 0 ? -nb : nb) % 10);
}

/*
** Convertis la taille de fichier representee par les parametres en chaine
** de caractere.
*/

static char		*size_to_string(off_t size_int, off_t size_dec, char size_suf)
{
	int		string_size;
	int		size_int_len;
	char	*result;

	string_size = 1;
	size_int_len = get_off_num_size(size_int);
	string_size += size_int_len;
	if (size_suf != 'B' && size_int < 10)
		string_size += 2;
	if ((result = ft_strnew(string_size)) == NULL)
		return (NULL);
	result[string_size - 1] = size_suf;
	if (size_suf != 'B' && size_int < 10)
	{
		result[string_size - 3] = '.';
		result[string_size - 2] = '0' + (size_dec % 10);
	}
	offtoa_inside(size_int, size_int_len, result);
	return (result);
}

/*
** Convertis la taille de type off_t en taille lisible dans une chaine de
** caractere.
*/

static char		*size_to_huread(off_t f_size)
{
	static char		size_letter[] = "BKMGTP";
	int				idx;
	off_t			old_size;
	double			decimal;

	old_size = f_size;
	decimal = 0;
	idx = 0;
	while (f_size >= 1000 && size_letter[idx + 1] != '\0')
	{
		old_size = f_size;
		decimal = (old_size / 1024.);
		f_size /= 1024;
		++idx;
	}
	if ((int)(decimal + 0.05) > (int)(decimal))
		++f_size;
	decimal += 0.05;
	return (size_to_string(f_size, ((int)(decimal * 10)) % 10,
				size_letter[idx]));
}

int				set_field_size(t_opts *opts, t_file *file, char **field)
{
	int		size_len;

	if (opts == NULL || file == NULL || field == NULL)
	{
		if (field != NULL)
			*field = NULL;
		return (0);
	}
	if (S_ISCHR(file->stat.st_mode) || S_ISBLK(file->stat.st_mode))
		*field = get_major_and_minor(file->stat.st_rdev);
	else if (get_opt(opts, LS_HUREAD) == 1)
		*field = size_to_huread(file->stat.st_size);
	else
	{
		size_len = get_off_num_size(file->stat.st_size);
		if ((*field = ft_strnew(size_len)) == NULL)
			return (0);
		offtoa_inside(file->stat.st_size, size_len, *field);
	}
	return (*field == NULL ? 0 : ft_strlen(*field));
}
