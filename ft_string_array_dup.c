/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_array_dup.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 20:16:50 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/18 20:37:10 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_string_array_count(const char **string_array)
{
	size_t	index;

	index = 0;
	while (string_array[index] != NULL)
		index++;
	return (index);
}

char	**ft_string_array_dup(const char **string_array)
{
	char	**dup;
	size_t	index;
	size_t	index_2;

	index_2 = 0;
	index = ft_string_array_count(string_array);
	dup = malloc(sizeof(char*) * (index + 1));
	if (dup != NULL)
	{
		while (index_2 < index)
		{
			dup[index_2] = ft_strdup(string_array[index_2]);
			if (dup[index_2] == NULL)
			{
				ft_free_string_array(&dup);
				return (NULL);
			}
			index_2++;
		}
		dup[index_2] = NULL;
	}
	return (dup);
}
