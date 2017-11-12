/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lst_variadic_err.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:58:13 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/12 15:13:14 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_defs.h"
#include "bool_interface.h"
#include <stdarg.h>

t_bool	f_lstiterr_vas(t_lst *lst,
		t_bool (*iter)(void *elem, va_list),
		va_list args)
{
	va_list	copy;

	while (lst != NULL)
	{
		va_copy(copy, args);
		if (!iter(lst->content, copy))
			return (FALSE);
		va_end(copy);
		lst = lst->next;
	}
	return (TRUE);
}

t_bool	f_lstiterr_va(t_lst *lst,
		t_bool (*iter)(void *elem, va_list),
		...)
{
	va_list	args;
	t_bool	result;

	va_start(args, iter);
	result = f_lstiterr_vas(lst, iter, args);
	va_end(args);
	return (result);
}
