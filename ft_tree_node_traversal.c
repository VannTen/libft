/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_node_traversal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 11:24:09 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/29 12:09:11 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree_node_defs.h"
#include "custom_stddef.h"
#include <stddef.h>

void	node_in_order_traversal(struct s_node *node, t_iter f)
{
	if (node != NULL)
	{
		node_in_order_traversal(node->left, f);
		f(node->content);
		node_in_order_traversal(node->right, f);
	}
}
