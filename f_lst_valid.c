/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lst_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 12:01:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/03 14:54:11 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_defs.h"
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

void	*f_lst_every_valid(t_lst *list, t_bool (*test)(const void *content))
{
	if (test == NULL)
		return (NULL);
	while (list != NULL)
	{
		if (test(list->content) == FALSE)
			return (list->content);
		else
			list = list->next;
	}
	return (list);
}
