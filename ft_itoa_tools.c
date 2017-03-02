/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:13:38 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/02 16:20:29 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_integer.h"
#include "bool.h"
#include <stddef.h>
#include <stdint.h>

size_t	itoa_len_signed(intmax_t number, int base)
{
	size_t	size;

	size = 0;
	if (number < 0)
		size++;
	while (number != 0)
	{
		number = number / base;
		size++;
	}
	return (size);
}

size_t	itoa_len_unsigned(uintmax_t number, int base)
{
	size_t	size;

	size = 0;
	while (number != 0)
	{
		number = number / base;
		size++;
	}
	return (size);
}

size_t	itoa_length(t_integer number, int base, t_bool is_signed)
{
	size_t	size;

	size = 0;
	if (is_signed)
		size = itoa_len_signed(number.negative, base);
	else
		size = itoa_len_unsigned(number.positive, base);
	return (size);
}

void	negative(char *str, intmax_t number, int base, char after_digits)
{
	char	digit;

	if (number == 0)
	{
		*str = '-';
		return ;
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
		return ;
	digit = number % base;
	if (digit < 10)
		*str = digit + '0';
	else
		*str = digit - 10 + after_digits;
	positive(str - 1, number / base, base, after_digits);
}
