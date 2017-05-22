/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_array_dup.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 20:16:50 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 15:49:48 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_array_defs.h"
#include "string_interface.h"
#include <stdlib.h>

size_t		ft_string_array_count(const char **string_array)
{
	size_t	index;

	index = 0;
	while (string_array[index] != NULL)
		index++;
	return (index);
}

static char	**content_copy(const char **src, char **dst, const size_t size)
{
	size_t	index;

	index = 0;
	while (index < size)
	{
		dst[index] = ft_strdup(src[index]);
		if (dst[index] == NULL)
		{
			ft_free_string_array(&dst);
			return (NULL);
		}
		index++;
	}
	dst[index] = NULL;
	return (dst);
}

char		**ft_string_array_dup(const char **string_array)
{
	char	**dup;
	size_t	size;

	if (string_array != NULL)
	{
		size = ft_string_array_count(string_array);
		dup = malloc(sizeof(char*) * (size + 1));
		if (dup != NULL)
			dup = content_copy(string_array, dup, size);
	}
	else
		dup = NULL;
	return (dup);
}
