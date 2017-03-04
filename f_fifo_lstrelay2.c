/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_fifo_lstrelay2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 13:38:21 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/04 13:42:48 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fifo.h"
#include "list.h"
#include "libft.h"

void	f_fifoiter(t_fifo *fifo, void (*f)(void*))
{
	f_lstiter_content(fifo->begin_lst, f);
}
