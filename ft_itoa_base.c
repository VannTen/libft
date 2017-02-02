/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 10:03:02 by exam              #+#    #+#             */
/*   Updated: 2017/02/02 14:13:34 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_integer.h"
#include "bool.h"
#include <stdlib.h>
#include <stdint.h>

size_t	itoa_length(t_integer number, int base, t_bool is_signed)
{
	size_t	size;

	size = 0;
	if (is_signed)
	{
		if (number.negative < 0)
			size++;
		while (number.negative != 0)
		{
			number.negative = number.negative / base;
			size++;
		}
	}
	else
	{
		while (number.positive != 0)
		{
			number.positive = number.positive / base;
			size++;
		}
	}
	return (size);
}

void	negative(char *str, intmax_t number, int base, char after_digits)
{
	char	digit;

	if (number == 0)
	{
		*str = '-';
		return;
	}
	digit = -(number % base);
	if (digit < 10)
		*str = digit + '0';
	else
		*str = digit - 10 + after_digits;
	negative(str - 1, number / base, base, after_digits);
}

void	positive(char *str, uintmax_t number, int base, char after_digits)
{
	char digit;

	if (number == 0)
		return;
	digit = number % base;
	if (digit < 10)
		*str = digit + '0';
	else
		*str = digit - 10 + after_digits;
	positive(str - 1, number / base, base, after_digits);
}

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
