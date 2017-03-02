/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_fifo_lstrelay.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 14:19:23 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/02 16:06:29 by mgautier         ###   ########.fr       */
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

void			*f_fifo_first_elem(const t_fifo *fifo)
{
	return (f_lst_first_elem(fifo->begin_lst));
}

void			f_fifoiterarray(void *array, t_fifo *fifo,
		void (*apply)(void *lst_content, void *array))
{
	f_lstiterarray(array, fifo->begin_lst, apply);
}

size_t			f_fifoarray_end_early(void *array, t_fifo *fifo,
		size_t size, t_bool (*fifo_on_array)(const void *content, void *array))
{
	return (f_lstarray_end_early(array, fifo->begin_lst, size, fifo_on_array));
}
