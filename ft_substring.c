/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 14:34:07 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 14:40:24 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_defs.h"
#include <stddef.h>

size_t	is_substring_up_to(const char *to_search, const char *to_be_searched)
{
	size_t	index;

	index = 0;
	while (to_search[index] == to_be_searched[index] && to_search != '\0')
		index++;
	return (index);
}
