/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 06:23:36 by wta               #+#    #+#             */
/*   Updated: 2018/12/10 07:58:01 by fwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/includes/ft_printf.h"
# include "libft/includes/libft.h"
# include <errno.h>
# include <string.h>
# include "options.h"
# include "file.h"

/*
** Structure de la liste chainee contenant le pointeur sur le
** prochain element de la liste et un pointeur sur les informations d'un
** fichier
*/
typedef struct	s_lst_ls
{
	struct s_lst_ls	*next;
	t_file			*file;
}				t_lst_ls;

typedef struct	s_fmt
{
	int	len_lst;
	int	min_w;
	int	max_col;
	int	max_row;
}				t_fmt;

/*
** Ajoute un maillon a la suite d'une liste chainee.
*/
void			lst_append(t_lst_ls **lst, t_lst_ls *node);

/*
**	Supprime une liste chainee.
*/
void			lst_rm(t_lst_ls *lst);

/*
** Recupere la taille d'une liste chainee.
*/
int				lst_size(t_lst_ls *lst);

/*
** Creer un nouveau maillon qui contient un pointeur sur structure sur les
** informations d'un fichier.
*/
t_lst_ls		*lst_newnode(t_file *file);

/*
** Cree une liste chainee qui lie tous les fichier d'un dossier depuis son
** chemin
*/
t_lst_ls		*link_file(char *path);

/*
** Cree un pointeur sur structure t_file contenant toutes les informations
** du fichier/dossier.
*/
t_file			*lst_newfile(DIR *pdir, char *path);

/*
** Genere le chemin d'un fichier/dossier.
*/
char			*get_new_path(char *path, char *name);

/*
** Trie une liste chainee.
*/
t_lst_ls		*lst_mergesort(t_lst_ls *lst, int len,
		int (*cmp_fun)(t_file *file1, t_file *file2));

/*
** Fonction de recursivite pour l'option -R
*/
void			ls_rec(char *path, char *currdir, t_opts *opts);

t_lst_ls		*find_dir(t_lst_ls *lst);

/*
** OUTIL DE TEST : Affiche le strict minimum des noms des t_file
*/
t_lst_ls		*skip_hidden(t_lst_ls *lst);

void			print_files(t_lst_ls *lst, t_opts *opts);

#endif
