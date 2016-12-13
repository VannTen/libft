/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strsplit_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:14:05 by mgautier          #+#    #+#             */
/*   Updated: 2016/12/13 15:05:40 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function proceeds with a loop performing the folowing actions :
** advance until the current characther is different from the separator
** if the string is not finished : count one field
** advance until the separator is found or the string ends
** repeat
** That is use to count the number of split to be created ; the function then
** allocates an array of strings of the appropriate size.
** The same loop (only difference is that the number of field is used for end
** condition) is then used to allocates each split.
** If any allocation fail, all allocated memory (previous allocated splits and
** the containing array) are freed and their pointers set to NULL, and NULL is
** returned.
*/

static char		*new_split(char const *src, size_t size)
{
	size_t	index;
	char	*split;

	index = 0;
	split = (char*)malloc(sizeof(char) * (size + 1));
	while (index < size)
		split[index] = src[index];
	split[size] = '\0';
	return (split);
}

char			**f_strsplit(char const *s, char c)
{
	size_t	index;
	size_t	index_current;
	t_lst	*strsplit;
	t_lst	*last;

	strsplit == NULL;
	last == NULL;
	index = 0;
	index_current = 0;
	while (s[index] != '\0')
	{
		if (s[index] == c)
		{
			last = f_add_end_lst(last,
					new_split(s + index_current, index - index_current));
			index++;
			index_current = index;
			if (strsplit == NULL)
				strsplit == last;
		}
		index++;
	}
	last = f_add_end_lst(last,
			new_split(s + index_current, index - index_current));
	return (strsplit);
}
