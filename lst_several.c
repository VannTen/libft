/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_several.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:40:28 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/14 12:58:08 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_defs.h"
#include <stddef.h>

t_lst	*last(t_lst *lst)
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}

t_lst	*join_lst(t_lst *lst_1, t_lst const *to_join)
{
	t_lst	*join;

	join = (t_lst*)to_join;
	if (lst_1 != NULL)
	{
		if (to_join != NULL)
			last(lst_1)->next = join;
		return (lst_1);
	}
	else
		return (join);
}

t_bool				lst_equ(t_lst const *lst1, t_lst const *lst2,
		t_bool (*equ)(void const*, void const*))
{
	while (lst1 != NULL && lst2 != NULL)
	{
		if (!equ(lst1->content, lst2->content))
			break ;
		lst1 = lst1->next;
		lst2 = lst2->next;
	}
	return (lst1 == NULL && lst2 == NULL);
}
