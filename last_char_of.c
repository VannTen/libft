/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_char_of.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 14:31:34 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/10 14:33:37 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	last_char_of(const char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len < 1)
		return ('\0');
	else
		return (str[len - 1]);
}
