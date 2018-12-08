/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 06:23:36 by wta               #+#    #+#             */
/*   Updated: 2018/12/08 09:59:12 by wta              ###   ########.fr       */
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

typedef	struct dirent	t_dirent;
typedef struct stat		t_stat;

/*
** t_file est la structure contenant toutes les informations relatives a un
** fichier.
*/
typedef struct	s_file
{
	t_dirent	*pdent;
	t_stat		stat;
	char		*path;
	int			time;
}				t_file;

/*
** t_lst_ls est la structure de la liste chainee contenant le pointeur sur le
** prochain element de la liste et un pointeur sur les informations d'un
** fichier
*/
typedef struct	s_lst_ls
{
	struct s_lst_ls	*next;
	t_file			*file;
}				t_lst_ls;

/*
** lst_append(t_lst_ls *lst, t_lst_ls *node)
** Ajoute un maillon a la suite d'une liste chainee.
*/
void		lst_append(t_lst_ls **lst, t_lst_ls *node);

/*
**	lst_rm(t_lst_ls *lst)
**	Supprime une liste chainee.
*/
void		lst_rm(t_lst_ls *lst);

/*
** lst_size(t_lst_ls *lst)
** Recupere la taille d'une liste chainee.
*/
int			lst_size(t_lst_ls *lst);

/*
** t_lst_ls	*lst_newnode(t_file *file)
** Creer un nouveau maillon qui contient un pointeur sur structure sur les
** informations d'un fichier.
*/
t_lst_ls	*lst_newnode(t_file *file);

/*
** t_lst_ls	*link_file(char *path)
** Cree une liste chainee qui lie tous les fichier d'un dossier depuis son 
** chemin
*/
t_lst_ls	*link_file(char *path);

/*
** Cree un pointeur sur structure t_file contenant toutes les informations
** du fichier/dossier.
 */
t_file		*ls_newfile(DIR *pdir, char *path);

/*
** Genere le chemin d'un fichier/dossier.
 */
char	*get_new_path(char *path, char *name);

/*
** t_lst_ls	*ls_mergesort(t_lst_ls *lst, int len)
** Trie une liste chainee.
*/
t_lst_ls	*lst_mergesort(t_lst_ls *lst, int len);

/*
** Fonction de recursivite pour l'option -R
 */
void	ls_rec(char *path);

/*
** OUTIL DE TEST : Affiche le strict minimum des noms des t_file
 */
void	print_files(t_lst_ls *lst);

#endif
