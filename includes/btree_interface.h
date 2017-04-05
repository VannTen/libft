/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_interface.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 16:41:43 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/05 17:20:34 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_INTERFACE_H
# define BTREE_INTERFACE_H
# include "custom_stddef.h"

typedef struct s_btree	t_btree;

/*
** Ressources management function
** Implementation file : ft_btree_ressources.c
*/

t_btree	*btree_create(t_compare f_comp);
void	btree_destroy(t_btree **place_to_destroy, t_destroy content_destroy);

/*
** Usage functions
** Implementation file : ft_btree_use.c
*/

void	btree_iter_in_order(t_btree *tree, t_iter f);
void	btree_iter_two_param_in_order(t_btree *tree,
		t_iter_two f, void *param_supp);
void	btree_iter_two_param_in_rev_order(t_btree *tree,
		t_iter_two f, void *param_supp);
void	*btree_add(t_btree *tree, void *content);

#endif
