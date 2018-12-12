/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 06:23:36 by wta               #+#    #+#             */
/*   Updated: 2018/12/12 18:17:54 by wta              ###   ########.fr       */
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

typedef struct	s_lst_info
{
	t_lst_ls	*head;
	t_lst_ls	*tail;
}				t_lst_info;

/*
** Ajoute un maillon a la suite d'une liste chainee.
*/
void			lst_append(t_lst_ls **head, t_lst_ls **tail, t_lst_ls *node);

/*
**	Supprime une liste chainee.
*/
void			lst_rm(t_lst_ls *lst, t_opts *opts);

/*
** Creer un nouveau maillon qui contient un pointeur sur structure sur les
** informations d'un fichier.
*/
t_lst_ls		*lst_newnode(t_file *file);

/*
** Cree une liste chainee qui lie tous les fichier d'un dossier depuis son
** chemin
*/
t_lst_ls		*link_file(char *path, t_opts *opts);

/*
** Cree un pointeur sur structure t_file contenant toutes les informations
** du fichier/dossier.
*/
t_file			*lst_newfile(DIR *pdir, char *path, t_opts *opts);

/*
** Genere le chemin d'un fichier/dossier.
*/
char			*get_new_path(char *path, char *name);

/*
** Trie une liste chainee.
*/
t_lst_ls		*lst_mergesort(t_lst_ls *lst,
		int (*cmp_fun)(t_file *file1, t_file *file2));

/*
** Fonction de recursivite pour l'option -R
*/
void			ls_rec(char *path, char *currdir, t_opts *opts);

t_lst_ls		*find_dir(t_lst_ls *lst);
t_lst_ls	*find_file(t_lst_ls *lst);

/*
** OUTIL DE TEST : Affiche le strict minimum des noms des t_file
*/
t_lst_ls		*skip_hidden(t_lst_ls *lst);

/*
** Affiche la liste des fichiers au format decrit par les options. Retourne -1
** en cas d'erreur et 0 en cas de succes.
*/
int				print_files(t_lst_ls *lst, t_opts *opts);

/*
** Initialise les fields du fichier selon les options et maj le format
** si besoin.
*/
int			init_file_infs(t_file *file, t_opts *opts);

int			is_curr_or_parent(t_dirent *pdent);

void	multiple_file(t_lst_info *lst, t_opts *opts, char *path);

#endif
