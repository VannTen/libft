/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_add_take.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 13:17:43 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/07 13:17:57 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree_defs.h"
#include "btree_node_interface.h"
#include <stddef.h>

void	*btree_add(t_btree *tree, void *content)
{
	if (tree != NULL)
	{
		if (tree->root != NULL)
			return (insert_node(tree->root, content, tree->f_comp));
		tree->root = insert_root(content);
		if (tree->root == NULL)
			return (content);
		else
			return (NULL);
	}
	else
		return (content);
}
