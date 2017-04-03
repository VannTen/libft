/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_fifo_add_take.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 13:12:14 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/31 13:13:20 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fifo_defs.h"

t_fifo	*f_fifo_add(t_fifo *fifo, const void *content)
{
	if (fifo == NULL)
		return (NULL);
	fifo->end_lst = f_add_end_lst(fifo->end_lst, content);
	if (fifo->end_lst == NULL)
		return (NULL);
	if (fifo->begin_lst == NULL)
		fifo->begin_lst = fifo->end_lst;
	return (fifo);
}

void	*f_fifo_take(t_fifo *fifo)
{
	void	*content;

	if (fifo == NULL || fifo->begin_lst == NULL)
		return (NULL);
	content = f_lstpop(&(fifo->begin_lst));
	if (fifo->begin_lst == NULL)
		fifo->end_lst = NULL;
	return (content);
}
