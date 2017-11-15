/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_lstmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:48:23 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/15 14:05:55 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_interface.h"
#include "fifo_interface.h"
#include "convert_interface.h"
#include "bool_interface.h"
#include "string_interface.h"
#include "misc_interface.h"
#include <stdlib.h>

t_lst	*convert_arr_to_struct(char **arr)
{
	size_t	index;
	t_fifo	*fifo;

	index = 0;
	fifo = f_fifo_create();
	if (fifo != NULL)
	{
		while (arr[index] != NULL)
		{
			f_fifo_add(fifo, arr[index]);
			index++;
		}
	}
	return (f_fifo_extract(&fifo));
}

static void	*lower_case(void const *str)
{
	return (ft_strmap(str, f_tolower));
}

static t_bool	cmp(const void *str1, const void *str2)
{
	return (ft_strequ(str1, str2));
}

int main(void)
{
	char	*str[] = {"A", "B", "D", "C", NULL};
	char	*str_2[] = {"a", "b", "d", "c", NULL};
	t_lst	*lst[3];
	t_bool	result;

	lst[0] = convert_arr_to_struct(str);
	lst[1] = convert_arr_to_struct(str_2);
	lst[2] = f_lstmap(lst[1], lower_case, ft_gen_strdel);
	result = lst_equ(lst[1], lst[2], cmp);
	f_lstdel(&lst[0], no_destroy);
	f_lstdel(&lst[1], no_destroy);
	f_lstdel(&lst[2], ft_gen_strdel);
	return (result);
}
