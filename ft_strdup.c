/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:45:40 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/29 15:47:22 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_defs.h"
#include <stdlib.h>

/*
** Make an allocated copy of src and return it.
** If allocation fail, NULL is returned.
*/

char	*ft_strdup(const char *src)
{
	size_t	len;
	size_t	cursor;
	char	*dest;

	if (src == NULL)
		return (NULL);
	len = ft_strlen(src);
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (dest);
	cursor = 0;
	while (cursor < len + 1)
	{
		dest[cursor] = src[cursor];
		cursor++;
	}
	return (dest);
}

char	*ft_strndup(const char *src, size_t size)
{
	size_t	len;
	size_t	cursor;
	char	*dest;

	len = ft_strnlen(src, size);
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (dest);
	cursor = 0;
	while (cursor < len)
	{
		dest[cursor] = src[cursor];
		cursor++;
	}
	dest[cursor] = '\0';
	return (dest);
}
