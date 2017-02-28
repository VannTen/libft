/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_fifo_lstrelay.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 14:19:23 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/28 16:47:35 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "fifo.h"
#include "libft.h"

unsigned int	f_fifomax(t_fifo *fifo, unsigned int (*get_max)(const void*))
{
	return (f_lstmax(fifo->begin_lst, get_max));
}

size_t			f_fifosumsize_t_content(t_fifo *fifo,
		size_t (*add)(const void*))
{
	return (f_lstsumsize_t_content(fifo->begin_lst, add));
}
