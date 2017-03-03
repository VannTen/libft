/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lstmax.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:33:54 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/03 17:23:52 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>
#include <limits.h>

int	f_lstmax(t_lst *list, int (*get_max)(const void *content))
{
	int	max;
	int	result;

	max = INT_MIN;
	while (list != NULL)
	{
		result = get_max(list->content);
		max = result > max ? result : max;
		list = list->next;
	}
	return (max);
}
