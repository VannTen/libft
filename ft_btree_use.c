/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_use.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:44:13 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/29 12:36:42 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree_defs.h"
#include "btree_node_interface.h"
#include "custom_stddef.h"
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

void	btree_iter_in_order(t_btree *tree, t_iter f)
{
	if (tree != NULL)
		node_in_order_traversal(tree->root, f);
}
