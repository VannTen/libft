/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_array_get.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 11:16:35 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/18 11:34:14 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_array_defs.h"
#include "string_interface.h"
#include <stddef.h>

size_t	ft_string_array_count(char const *const *str_array)
{
	size_t	index;

	index = 0;
	while (str_array[index] != NULL)
		index++;
	return (index);
}

int		ft_str_arraycmp(char const *const *array_1, char const *const *array_2)
{
	int		result;
	size_t	index;

	result = 0;
	index = 0;
	while (result == 0
			&& array_1[index] != NULL
			&& array_2[index] != NULL)
	{
		result = ft_strcmp(array_1[index], array_2[index]);
		index++;
	}
	if (result != 0)
		return (result);
	else if (index == 0)
		return (array_1[index] == NULL ? 0 : 1);
	else
		return (array_1[index - 1] == NULL ? 0 : 1);
}
