/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 10:03:02 by exam              #+#    #+#             */
/*   Updated: 2017/03/02 16:18:29 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_integer.h"
#include "itoa_tools.h"
#include "bool.h"
#include <stdlib.h>
#include <stdint.h>

char	*ft_itoa_base(t_integer value, int base, t_bool maj, t_bool is_signed)
{
	size_t	size;
	char	*itoa;

	if (base < 2)
		return (NULL);
	size = itoa_length(value, base, is_signed);
	itoa = (char*)malloc(sizeof(char) * (size + 1));
	itoa[size] = '\0';
	if (is_signed)
	{
		if (value.negative < 0)
			negative(itoa + size - 1, value.negative, base, maj ? 'A' : 'a');
		else
		{
			value.positive = value.negative;
			is_signed = FALSE;
		}
	}
	if (!is_signed)
		positive(itoa + size - 1, value.positive, base, maj ? 'A' : 'a');
	return (itoa);
}
