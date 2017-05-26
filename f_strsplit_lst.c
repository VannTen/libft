/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strsplit_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:14:05 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/26 16:44:34 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst_interface.h"
#include "fifo_interface.h"
#include "string_interface.h"
#include <stdlib.h>

/*
** The function proceeds with a loop performing the folowing actions :
** advance until the current characther is different from the separator,
** while keeping an index to the previous separator (first being the beginning
** of the string).
** Then, send to new_split the adress of the first character of the current
** string split, and the size of the split (the current index minus the index of
** the previous separator).
** new_split then produces a lst link, which is put at the end of the list.
*/

static char		*new_split(char const *src, size_t size)
{
	size_t	index;
	char	*split;

	index = 0;
	split = malloc(sizeof(char) * (size + 1));
	if (split != NULL)
	{
		while (index < size)
		{
			split[index] = src[index];
			index++;
		}
		split[size] = '\0';
	}
	return (split);
}

t_lst			*f_strsplit_lst(char const *s, const char c)
{
	size_t	index;
	size_t	index_current;
	t_fifo	*strsplit;
	char	*split;

	strsplit = f_fifo_create();
	index = 0;
	while (s != NULL && strsplit != NULL)
	{
		index_current = index;
		while (s[index] != c && s[index] != '\0')
			index++;
		split = new_split(s + index_current, index - index_current);
		if (split == NULL)
			f_fifo_destroy(&strsplit, ft_gen_strdel);
		f_fifo_add(strsplit, split);
		if (s[index] == '\0')
			break ;
		index++;
	}
	return (f_fifo_extract(&strsplit));
}
