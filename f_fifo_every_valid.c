/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_fifo_every_valid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:19:05 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/14 18:31:58 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fifo_defs.h"
#include "lst_interface.h"
#include <stdarg.h>

void	*f_fifo_every_valid(t_fifo const *fifo, t_bool (*test)(const void *content))
{
	return (f_lst_every_valid(fifo->begin_lst, test));
}

void	*f_fifo_every_valid_va(
		t_fifo const *fifo,
		t_bool (*test)(const void *content, va_list args),
		...)
{
	void	*ret;
	va_list	args;

	va_start(args, test);
	ret = f_lst_every_valid_vas(fifo->begin_lst, test, args);
	va_end(args);
	return (ret);
}

void	*f_fifo_every_valid_vas(
		t_fifo const *fifo,
		t_bool (*test)(const void *content, va_list args),
		va_list args)
{
	return (f_lst_every_valid_vas(fifo->begin_lst, test, args));
}
