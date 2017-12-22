/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:39:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/22 15:45:19 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_defs.h"
#include <assert.h>
#include <stddef.h>

static t_bool	add(void *add_from, va_list args)
{
	return (NULL != f_lstpush(add_from, va_arg(args, t_lst**)));
}

t_lst	*lst_add_to(t_lst **add_to, t_lst const *add_from)
{
	assert(add_to != NULL);
	if (f_lstiterr_va((t_lst*)add_from, add, add_to))
		return (*add_to);
	else
		return (NULL);
}
