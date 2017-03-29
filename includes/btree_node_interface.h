/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_node_interface.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 10:12:46 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/29 10:36:29 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_NODE_INTERFACE_H
# define BTREE_NODE_INTERFACE_H
# include "custom_stddef.h"

struct s_node;

/*
** Ressourcs management
** Implementation file : ft_tree_node_ressources.c
*/

void			node_destroy(struct s_node **to_destroy, t_destroy destructor);
struct s_node	*node_create(void);

/*
** Tree insertion
** Implementation file : ft_tree_node_insert.c
*/

void			*insert_node(struct s_node *node, void *content, t_compare comp);

#endif
