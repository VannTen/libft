/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lstsum_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:17:23 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/02 16:07:14 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stddef.h>

int		f_lstsum_content(t_lst *list, int (*f)(const void *))
{
	int	sum;

	sum = 0;
	while (list != NULL)
	{
		sum += f(list->content);
		list = list->next;
	}
	return (sum);
}

size_t	f_lstsumsize_t_content(t_lst *list, size_t (*f)(const void *))
{
	size_t	sum;

	sum = 0;
	while (list != NULL)
	{
		sum += f(list->content);
		list = list->next;
	}
	return (sum);
}
