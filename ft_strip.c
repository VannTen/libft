/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strip.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 13:47:54 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/09 13:56:21 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_defs.h"
#include "issomething_interface.h"

static char	*copy_new(char const *src, char const *to_strip, size_t	index_dest)
{
	char	*dest;
	size_t	index;

	dest = NULL;
	dest = ft_strnew(index_dest);
	if (dest != NULL)
	{
		index_dest = 0;
		index = 0;
		while (src[index] != '\0')
		{
			if (!is_among(to_strip, src[index]))
			{
				dest[index_dest] = src[index];
				index_dest++;
			}
			index++;
		}
	}
	return (dest);
}

char	*ft_strip(char const *src, char const *to_strip)
{
	size_t	index;
	size_t	index_dest;

	index = 0;
	index_dest = 0;
	while (src[index] != '\0')
	{
		if (!is_among(to_strip, src[index]))
			index_dest++;
		index++;
	}
	if (index_dest != 0)
		return (copy_new(src, to_strip, index_dest));
	else
		return (NULL);
}
