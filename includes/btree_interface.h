/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_interface.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 16:41:43 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/28 17:57:50 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_INTERFACE_H
# define BTREE_INTERFACE_H

typedef struct s_btree t_btree;
typedef int	(*t_compare)(void *ref, void *to_comp);

/*
** Ressources management function
** Implementation file : ft_btree_ressources.c
*/

t_btree	*btree_create(t_compare f_comp);
void	btree_destroy(t_btree **place_to_destroy,
		void (*content_destroy)(void *content));

#endif
