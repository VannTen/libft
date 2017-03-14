/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_tools.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:15:30 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/14 19:24:50 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITOA_TOOLS_H
# define ITOA_TOOLS_H
# include "bool.h"
# include "ft_integer.h"
# include <stddef.h>
# include <stdint.h>
# define DECIMAL_DIGITS "0123456789"
# define OCTAL_DIGITS "01234567"
# define BINARY_DIGITS "01"
# define HEXADECIMAL_DIGITS "0123456789abcdef"
# define HEXADECIMAL_DIGITS_CAPS "0123456789ABCDEF"
# define DECIMAL_BASE sizeof(DECIMAL_DIGITS) - 1
# define OCTAL_BASE sizeof(OCTAL_DIGITS) - 1
# define BINARY_BASE sizeof(BINARY_DIGITS) - 1
# define HEXADECIMAL_BASE sizeof(HEXADECIMAL_DIGITS) - 1

size_t	itoa_len_signed(intmax_t number, int base);
size_t	itoa_len_unsigned(uintmax_t number, unsigned int base);
size_t	itoa_length(t_integer number, int base, t_bool is_signed);
void	itoa_write_signed(char *str, intmax_t number, unsigned int base,
		const char *base_digits);
void	itoa_write_unsigned(char *str, uintmax_t number, unsigned int base,
		const char *base_digits);

#endif
