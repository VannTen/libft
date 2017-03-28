/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_use.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:44:13 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/28 18:54:26 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree_defs.h"

static void	*insert_left(struct s_node *node, void *content, t_compare comp)
{
	if (node->left == NULL)
	{
		node->left = create_node();
		if (node->left != NULL)
			node->left->content = content;
		return (NULL);
	}
	else
		return (insert_node(node->left, void *content, t_compare comp));
}

static void	*insert_right(struct s_node *node, void *content, t_compare comp)
{
	if (node->right == NULL)
	{
		node->right = create_node();
		if (node->right != NULL)
			node->right->content = content;
		return (NULL);
	}
	else
		return (insert_node(node->right, void *content, t_compare comp));
}

static void	*insert_node(struct s_node *node, void *content, t_compare comp)
{
	int	comp_result;

	comp_result = comp(ref, node->content);
	if (comp_result < 0)
		return (insert_left(node, content, comp));
	else if (comp_result > 0)
		return (insert_right(node, content, comp));
	else
		return (content);
}

void	*btree_add(t_btree *tree, void *content)
{
	if (tree != NULL)
		return (insert_node(tree->root, content, tree->f_comp));
	else
		return (NULL);
}
