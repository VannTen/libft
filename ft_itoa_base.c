/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 10:03:02 by exam              #+#    #+#             */
/*   Updated: 2017/02/02 11:42:29 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	string_length(int number, int base)
{
	size_t	size;

	size = 0;
	if ((number < 0 && base == 10) || number == 0)
		size++;
	while (number != 0)
	{
		number = number / base;
		size++;
	}
	return (size);
}

void	negative(char *str, int number, int base)
{
	char	digit;

	if (number == 0)
		return;
	digit = -(number % base);
	if (digit < 10)
		*str = digit + '0';
	else
		*str = digit - 10 + 'A';
	negative(str - 1, number / base, base);
}

void	positive(char *str, int number, int base)
{
	char digit;

	if (number == 0)
		return;
	digit = number % base;
	if (digit < 10)
		*str = digit + '0';
	else
		*str = digit - 10 + 'A';
	positive(str - 1, number / base, base);
}

char	*ft_itoa_base(int value, int base)
{
	size_t	size;
	char	*itoa;

	if (base < 2)
		return (NULL);
	size = string_length(value, base);
	itoa = (char*)malloc(sizeof(char) * (size + 1));
	itoa[size] = '\0';
	if (value < 0 && base == 10)
		*itoa = '-';
	if (value < 0)
		negative(itoa + size - 1, value, base);
	else if (value > 0)
		positive(itoa + size - 1, value, base);
	else
		*itoa = '0';
	return (itoa);
}
