/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lstmax.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:33:54 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/10 16:32:25 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>
#include <limits.h>

size_t	f_lstmax(t_lst *list, size_t (*get_max)(const void *content))
{
	size_t	max;
	size_t	result;

	max = 0;
	while (list != NULL)
	{
		result = get_max(list->content);
		max = result > max ? result : max;
		list = list->next;
	}
	return (max);
}
