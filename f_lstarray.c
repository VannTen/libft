/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lstarray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:10:01 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/02 16:06:55 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "list.h"
#include <stdlib.h>

size_t	f_lstarray_end_early(void *array, t_lst *lst, size_t size,
		t_bool (*put_lst_on_array)(const void *lst_content, void *array))
{
	size_t	count;

	count = size;
	while (count != 0 && lst != NULL)
	{
		if (put_lst_on_array(lst->content, array))
			count--;
		lst = lst->next;
	}
	return (count);
}

void	f_lstiterarray(void *array, t_lst *lst,
		void (*apply)(void *lst_content, void *array))
{
	while (lst != NULL)
	{
		apply(lst->content, array);
		lst = lst->next;
	}
}
