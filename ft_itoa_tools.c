/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:13:38 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/10 11:58:49 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_integer.h"
#include "bool.h"
#include "itoa_tools.h"
#include <stddef.h>
#include <stdint.h>

size_t	itoa_len_signed(intmax_t number, int base)
{
	size_t	size;

	size = 1;
	while (number >= base)
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

void	itoa_write_signed(char *str, intmax_t number, const unsigned int base,
		const char *base_digits)
{
	int	digit;

	digit = number % base;
	if (number < 0)
		digit = -digit;
	*str = base_digits[digit];
	if (number < base)
		return ;
	else
		itoa_write_signed(str - 1, number / base, base, base_digits);
}

void	itoa_write_unsigned(char *str, uintmax_t number, const unsigned int base,
		const char *base_digits)
{
	int digit;

	digit = number % base;
	*str = base_digits[digit];
	if (number < base)
		return ;
	else
		itoa_write_unsigned(str - 1, number / base, base, base_digits);
}
