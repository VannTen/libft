/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lst_get_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 14:27:03 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/31 14:41:30 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_defs.h"

void	*f_lstsearch(const t_lst *list, const int ref,
		int (*match)(const t_lst *elem))
{
	while (list != NULL)
	{
		if (ref == match(list))
			return (list->content);
		list = list->next;
	}
	return (NULL);
}

void	*f_lst_first_elem(const t_lst *lst)
{
	return (lst->content);
}
