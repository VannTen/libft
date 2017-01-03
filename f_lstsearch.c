/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lstsearch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:53:38 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/03 14:57:29 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stldib.h>

/*
** Returns first element that returns the integer ref when the function match
** is applied to it
*/

t_lst	*f_lstsearch(t_lst *list, int ref, int (*match)(t_lst *elem))
{
	while (list != NULL)
	{
		if (ref == match(list))
			return (list);
	}
}
