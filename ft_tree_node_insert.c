/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_node_insert.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 10:15:46 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/29 11:20:27 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree_node_defs.h"
#include <stddef.h>

static void	*insert_left(struct s_node *node, void *content, t_compare comp)
{
	if (node->left == NULL)
	{
		node->left = node_create();
		if (node->left != NULL)
			node->left->content = content;
		return (NULL);
	}
	else
		return (insert_node(node->left, content,comp));
}

static void	*insert_right(struct s_node *node, void *content, t_compare comp)
{
	if (node->right == NULL)
	{
		node->right = node_create();
		if (node->right != NULL)
			node->right->content = content;
		return (NULL);
	}
	else
		return (insert_node(node->right, content, comp));
}

void		*insert_node(struct s_node *node, void *content, t_compare comp)
{
	int	comp_result;

	comp_result = comp(content, node->content);
	if (comp_result < 0)
		return (insert_left(node, content, comp));
	else if (comp_result > 0)
		return (insert_right(node, content, comp));
	else
		return (content);
}
