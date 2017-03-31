/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_fifo_lstrelay2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:38:21 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/31 15:09:45 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fifo_defs.h"
#include "lst_interface.h"

int		f_fifodosum(t_fifo *fifo, int (*add)(void*))
{
	return (f_lstdosum(fifo->begin_lst, add));
}

void	f_fifoiter(t_fifo *fifo, void (*f)(void*))
{
	f_lstiter(fifo->begin_lst, f);
}

void	f_fifomaparray(const void *src, void *dst, t_fifo *fifo,
		t_bool (*advance_arrays)(const void **src, void **dst, void *modifier))
{
	f_lstmaparray(src, dst, fifo->begin_lst, advance_arrays);
}

void	*f_fifo_every_valid(t_fifo *fifo, t_bool (*test)(const void *content))
{
	return (f_lst_every_valid(fifo->begin_lst, test));
}
