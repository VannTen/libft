/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:18:46 by mgautier          #+#    #+#             */
/*   Updated: 2017/12/22 15:40:33 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_interface.h"
#include "conv_data_struct_interface.h"
#include "useful_macros.h"

static t_bool	equ(void const *elem1, void const *elem2)
{
	return ((elem1 == NULL && elem2 == elem1)
			|| *(char*)elem1 == *(char*)elem2);
}

int				main(void)
{
	t_lst	list[3];
	t_bool	result;

	list[0] = array_to_lst_index((char*[4]){"A", "B", NULL, "C"}, 4);
	list[1] = array_to_lst_index((char*[3]){"D", "E", "F"}, 3);
	list[2] = array_to_lst_index((char*[7]){"A", "B", NULL, "C"}, 7);
	lst_add_to(&list[0], list[1]);
	result =
		lst_same_contents(list[0], list[2], equ)
		&& f_lstlen(list[1]) == 3;
	f_lstdel(&list[0], no_destroy);
	f_lstdel(&list[1], no_destroy);
	f_lstdel(&list[2], no_destroy);
	RET_TEST(result);
}
