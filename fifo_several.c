/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo_several.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:38:39 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/28 12:43:29 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fifo_defs.h"
#include "lst_interface.h"

t_bool	fifo_are_equ(t_fifo const *fifo_1, t_fifo const *fifo_2,
		t_bool (*is_equ)(void const*, void const*))
{
	return (lst_equ(fifo_1->begin_lst, fifo_2->begin_lst, is_equ));
}
