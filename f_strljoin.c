/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strljoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:38:47 by mgautier          #+#    #+#             */
/*   Updated: 2016/12/13 15:06:54 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** f_strljoin
**
** Join two strings whose total lenght should be equal to size ;
** if that is not the case, f_strljoin will form a string of up to size
** characters, copying str_1, then str_2, until it reaches it's size limit.
** If ft_strlen(str_1) + ft_strlen(str_2) is bigger than size, then join is
** not terminated.
*/

char	*f_strljoin(const char *str_1, const char *str_2, const size_t size)
{
	char	*join;
	size_t	index;

	index = 0;
	join = (char*)malloc(sizeof(char) * (size + 1));
	if (join == NULL)
		return (NULL);
	while (str_1 != '\0' && index < size)
	{
		join[index] = str_1[index];
		index++;
	}
	while (index <= size)
	{
		join[index] = *str_2;
		index++;
		str_2++;
	}
	return (join);
}
