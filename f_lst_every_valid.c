/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lst_every_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 12:01:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/22 11:08:06 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "bool.h"
#include <stdlib.h>

/*
** Check every link of a list with a given test function.
** If all links pass the test, the function returns NULL.
** Otherwise, it returns the adress of the first link that does not pass the
** test.
**
** If any of the arguments is NULL, the function returns NULL : a non existent
** test is true for any link, and a non existent list can't fail the test.
*/

t_lst	*f_lst_every_valid(t_lst *list, t_bool (*test)(const void *content))
{
	if (test == NULL)
		return (NULL);
	while (list != NULL)
	{
		if (test(list->content) == FALSE)
			break ;
		else
			list = list->next;
	}
	return (list);
}
