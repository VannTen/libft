/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo_defs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 18:28:45 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/31 13:19:57 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIFO_DEFS_H
# define FIFO_DEFS_H
# include "fifo_interface.h"
# include "list.h"

struct	s_fifo
{
	t_lst	*begin_lst;
	t_lst	*end_lst;
};

#endif
