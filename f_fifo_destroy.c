/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_fifo_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 21:22:03 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/03 16:47:51 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fifo.h"
#include "libft.h"
#include <stdlib.h>

void	f_fifo_destroy(t_fifo *fifo, void (*del)(void *content))
{
	if (fifo != NULL && del != NULL)
	{
		f_lstdel(fifo->begin_lst, del);
		fifo->end_lst = NULL;
	}
	free(fifo);
}
