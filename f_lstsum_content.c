/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lstsum_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:17:23 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/23 13:23:31 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	f_lstsum_content(t_lst *list, int (*f)(const void *))
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
