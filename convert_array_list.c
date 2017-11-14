/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_array_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:30:47 by mgautier          #+#    #+#             */
/*   Updated: 2017/11/14 13:29:23 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_data_struct_defs.h"
#include "lst_defs.h"
#include "misc_interface.h"
#include "string_interface.h"
#include <stdlib.h>

t_lst	*str_to_lst(char const *str)
{
	t_lst	*new_list;
	t_lst	*end;
	size_t	index;

	end = NULL;
	new_list = NULL;
	index = 0;
	while (str[index] != '\0')
	{
		if (NULL == f_add_end_lst_2(&end, str + index))
		{
			f_lstdel(&new_list, no_destroy);
			break ;
		}
		if (index == 0)
			new_list = end;
		index++;
	}
	return (new_list);
}

char	*lst_to_str(t_lst const *lst)
{
	char	*new_str;
	size_t	index;

	index = 0;
	new_str = ft_strnew(f_lst_len(lst));
	if (new_str != NULL)
	{
		while (lst != NULL)
		{
			new_str[index] = *(char*)lst->content;
			index++;
			lst = lst->next;
		}
	}
	return (new_str);
}
