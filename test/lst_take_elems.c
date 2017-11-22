/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_take_elems.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:32:28 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/22 13:41:09 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_interface.h"
#include "string_interface.h"
#include "misc_interface.h"
#include "bool_interface.h"
#include "fifo_interface.h"
#include "useful_macros.h"
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
	return (ft_strequ(elem, va_arg(args, char const*))
				|| ft_strequ(elem, va_arg(args, char const*)));
}

static t_bool	test_take_one(char **str)
{
	t_lst	*lst;
	char	*str_in;
	t_bool	result;

	lst = convert_arr_to_struct(str);
	str_in = f_lsttakeone_if_va(&lst, TRUE, match, "bar", "BAR");
	result = ft_strequ(str_in, "BAR");
	f_lstdel(&lst, no_destroy);
	return (result);
}

static t_bool	test_split_lst(char **str, char **str1, char **str2,
		char **str4)
{
	t_lst	*lst[6];
	size_t	index;
	t_bool	result;

	lst[0] = convert_arr_to_struct(str);
	lst[1] = convert_arr_to_struct(str1);
	lst[2] = convert_arr_to_struct(str2);
	lst[3] = convert_arr_to_struct(str4);
	lst[4] = f_split_lst_va(&lst[0], TRUE, match, "bar", "BAR");
	lst[5] = f_split_lst_va(&lst[3], TRUE, match, "bar", "BAR");
	result = lst_equ(lst[0], lst[1], ft_gen_strequ)
		&& lst_equ(lst[2], lst[4], ft_gen_strequ)
		&& f_lst_len(lst[0]) == 2
		&& f_lst_len(lst[4]) == 3
		&& lst_equ(lst[2], lst[5], ft_gen_strequ);
	index = 0;
	while (index < ARRAY_LENGTH(lst))
	{
		f_lstdel(&lst[index], no_destroy);
		index++;
	}
	return (result);
}

int				main(void)
{
	char	*str_0[] = {"BAR", "", "", "YYYUU" , "",
		"FOO", "foo", "bar", "bar", NULL };
	char	*str[] = {"FOO", "BAR", "foo", "bar", "bar", NULL};
	char	*str_1[] = {"FOO", "foo", NULL};
	char	*str_2[] = {"BAR", "bar", "bar", NULL};

	return (test_take_one(str)
			&& test_split_lst(str, str_1, str_2, str_0) ?
			EXIT_SUCCESS : EXIT_FAILURE);
}
