/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_use.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:44:13 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/29 10:47:55 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree_defs.h"
#include <stddef.h>

void	*btree_add(t_btree *tree, void *content)
{
	if (tree != NULL)
		return (insert_node(tree->root, content, tree->f_comp));
	else
		return (NULL);
}
