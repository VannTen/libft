/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lstmax.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:33:54 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/08 18:09:27 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

unsigned int	f_lstmax(t_lst *list,
		unsigned int (*get_max)(const void *content))
{
	unsigned int	max;
	unsigned int	result;

	max = 0;
	while (list != NULL)
	{
		result = get_max(list->content);
		max = result > max ? result : max;
		list = list->next;
	}
	return (max);
}
