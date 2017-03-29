/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lstsum_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:17:23 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/22 16:01:52 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stddef.h>

int		f_lstsum_content(t_lst *list, int (*f)(const void *))
{
	int	sum;
	int	result;

	sum = 0;
	while (list != NULL)
	{
		result = f(list->content);
		if (result < 0)
			break ;
		sum += result;
		list = list->next;
	}
	return (sum);
}

int		f_lstdosum(t_lst *list, int (*f)(void *))
{
	int	sum;
	int	result;

	sum = 0;
	while (list != NULL)
	{
		result = f(list->content);
		if (result < 0)
			break ;
		sum += result;
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
