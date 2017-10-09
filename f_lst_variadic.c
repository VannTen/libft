/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lst_variadic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:43:57 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/09 17:23:07 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_defs.h"
#include "bool_interface.h"
#include <stddef.h>
#include <stdarg.h>

void	f_lstremoveif_va(t_lst **lst,
		t_bool (*match)(const void *elem, va_list),
		t_destroy content_dtor, ...)
{
	t_lst	*to_del;
	va_list	args;

	while (*lst != NULL)
	{
		va_start(args, content_dtor);
		if (match((*lst)->content, args))
		{
			to_del = *lst;
			*lst = (*lst)->next;
			f_lstdelone(to_del, content_dtor);
		}
		else
			lst = &(*lst)->next;
		va_end(args);
	}
}

void	f_lstiter_va(t_lst const *lst,
		void (*iter)(const void *elem, va_list),
		...)
{
	va_list	args;

	while (lst != NULL)
	{
		va_start(args, iter);
		iter(lst->content, args);
		va_end(args);
		lst = lst->next;
	}
}
