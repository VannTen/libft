/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_array_count.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:08:13 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/29 11:08:48 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_array_defs.h"
#include <stddef.h>

size_t		ft_string_array_count(const char **string_array)
{
	size_t	index;

	index = 0;
	while (string_array[index] != NULL)
		index++;
	return (index);
}
