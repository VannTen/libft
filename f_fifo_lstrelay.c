/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_fifo_lstrelay.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 14:19:23 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/21 14:40:47 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "fifo.h"
#include "libft.h"

unsigned int	f_fifomax(t_fifo *fifo, unsigned int (*get_max)(const void*))
{
	return (f_lstmax(fifo->begin_lst, get_max));
}
