/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_attr_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wta <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:11:59 by wta               #+#    #+#             */
/*   Updated: 2018/12/12 17:12:08 by wta              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "sys/types.h"
#include "sys/xattr.h"
#include "sys/acl.h"

int		has_xattr(char *filepath)
{
	return (listxattr(filepath, NULL, 0, XATTR_NOFOLLOW) > 0);
}

int		has_acl(char *filepath)
{
	acl_t	acl;
	int		res;

	acl = NULL;
	acl = acl_get_link_np(filepath, ACL_TYPE_EXTENDED);
	res = (acl != NULL) ? 1 : 0;
	acl_free(acl);
	acl = NULL;
	return (res);
}
