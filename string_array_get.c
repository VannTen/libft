/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_array_get.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 11:16:35 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/10 11:23:20 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_array_defs.h"
#include <stddef.h>

size_t	ft_string_array_len(char const *const *str_array)
{
	size_t	index;

	index = 0;
	while (str_array[index] != NULL)
		index++;
	return (index);
}
