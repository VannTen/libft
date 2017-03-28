/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_defs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 16:41:31 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/28 17:13:45 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_DEFS_H
# define BTREE_DEFS_H
# include "btree_interface.h"

struct	s_node
{
	void			*content;
	struct s_node	*left;
	struct s_node	*right;
};

struct	s_btree
{
	struct s_node	*root;
	t_compare			f_comp;
};

#endif
