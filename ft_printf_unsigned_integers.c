/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_integers.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:23:52 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/27 11:27:49 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "variadic_args_interface.h"
#include "itoa_tools.h"

static void	print_unsigned(char *to_write, const t_conversion *conv, int base,
		char *base_digits)
{
	int index;

	index = 0;
	if (!conv->flags[NEGATIVE_FIELD_WIDTH])
		index += ft_write_field_width(to_write, conv->field_width.param.value
				- conv->precision.param.value,
				conv->flags[ZERO_PADDING] ? '0' : ' ');
	index += ft_write_precision(to_write + index, conv);
	itoa_write_unsigned(to_write + index + conv->result_length - 1,
			ft_var_unsigned_integers(conv->arg), base, base_digits);
	index += conv->result_length;
	if (conv->flags[NEGATIVE_FIELD_WIDTH])
		index += ft_write_field_width(to_write + index,
				conv->field_width.param.value - conv->precision.param.value,
				conv->flags[ZERO_PADDING] ? '0' : ' ');
}

int			ft_printf_len_o(t_conversion *conv)
{
	int result;

	result = itoa_len_unsigned(ft_var_unsigned_integers(conv->arg), 8);
	conv->result_length = result;
	if (conv->flags[ALTERNATE_FORM] && conv->precision.param.value <= result)
		conv->precision.param.value = result + 1;
	else if (result > conv->precision.param.value)
		conv->precision.param.value = result;
	if (conv->precision.param.value > conv->field_width.param.value)
		conv->field_width.param.value = conv->precision.param.value;
	return (conv->field_width.param.value);
}

void		ft_print_to_o(char *to_write, const t_conversion *conv)
{
	print_unsigned(to_write, conv, 8, OCTAL_DIGITS);
}

int			ft_printf_len_u(t_conversion *conv)
{
	int result;

	result = itoa_len_unsigned(ft_var_unsigned_integers(conv->arg), 10);
	conv->result_length = result;
	if (result > conv->precision.param.value)
		conv->precision.param.value = result;
	if (conv->precision.param.value > conv->field_width.param.value)
		conv->field_width.param.value = conv->precision.param.value;
	return (conv->field_width.param.value);
}

void		ft_print_to_u(char *to_write, const t_conversion *conv)
{
	print_unsigned(to_write, conv, 10, DECIMAL_DIGITS);
}
