/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_take_elems.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:32:28 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/17 14:41:01 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_interface.h"
#include "string_interface.h"
#include "misc_interface.h"
#include "bool_interface.h"
#include "fifo_interface.h"
#include <stdarg.h>
#include <stdlib.h>

static t_lst	*convert_arr_to_struct(char **arr)
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

static t_bool	match(void const *elem, va_list args)
{
	(void)args;
	return (ft_strequ(elem, "bar") || ft_strequ(elem, "BAR"));
}

static t_bool	test_take_one(char **str)
{
	t_lst	*lst;
	char	*str_in;
	t_bool	result;

	lst = convert_arr_to_struct(str);
	str_in = f_lsttakeone_if_va(&lst, TRUE, match);
	result = ft_strequ(str_in, "BAR");
	f_lstdel(&lst, no_destroy);
	return (result);
}

static t_bool	test_split_lst(char **str, char **str1, char **str2)
{
	t_lst	*lst[4];
	size_t	index;
	t_bool	result;

	lst[0] = convert_arr_to_struct(str);
	lst[1] = convert_arr_to_struct(str1);
	lst[2] = convert_arr_to_struct(str2);
	lst[3] = f_split_lst_va(&lst[0], TRUE, match);
	result = lst_equ(lst[0], lst[1], ft_gen_strequ)
		&& lst_equ(lst[2], lst[3], ft_gen_strequ);
	index = 0;
	while (index < 4)
	{
		f_lstdel(&lst[index], no_destroy);
		index++;
	}
	return (result);
}

int				main(void)
{
	char	*str[] = {"FOO", "BAR", "foo", "bar", NULL};
	char	*str_1[] = {"FOO", "foo", NULL};
	char	*str_2[] = {"BAR", "bar", NULL};

	return (test_take_one(str)
			&& test_split_lst(str, str_1, str_2) ?
			EXIT_SUCCESS : EXIT_FAILURE);
}
