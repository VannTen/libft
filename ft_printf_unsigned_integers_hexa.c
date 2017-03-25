/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_integers_hexa.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 19:02:34 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/25 11:05:45 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "variadic_args_interface.h"
#include "itoa_tools.h"
#include "libft.h"

static void	print_hexa(char *to_write, const t_conversion *conv, int base,
		char *base_digits)
{
	int index;

	index = 0;
	if (!conv->flags[NEGATIVE_FIELD_WIDTH])
		index += ft_write_field_width(to_write, conv->field_width.param.value
				- conv->precision.param.value,
				conv->flags[ZERO_PADDING] ? '0' : ' ');
	if (conv->flags[ALTERNATE_FORM])
	{
		ft_strcpy(to_write, conv->type == X ?
				HEXA_ALTERNATE_FORM : HEXA_MAJ_ALTERNATE_FORM);
		index += ft_strlen(HEXA_ALTERNATE_FORM);
	}
	index += ft_write_precision(to_write, conv);
	itoa_write_unsigned(to_write + index + conv->result_length - 1,
			ft_var_unsigned_integers(conv->arg), base, base_digits);
	if (conv->flags[NEGATIVE_FIELD_WIDTH])
		index += ft_write_field_width(to_write + index,
				conv->field_width.param.value - conv->precision.param.value,
				' ');
}

int		ft_printf_len_x(t_conversion *conv)
{
	int result;

	if (conv->flags[ZERO_PADDING])
		conv->precision.param.value =
			conv->field_width.param.value - count_alternate_form(conv);
	result = itoa_len_unsigned(ft_var_unsigned_integers(conv->arg), 16);
	conv->result_length = result;
	if (result > conv->precision.param.value)
		conv->precision.param.value = result;
	if (conv->precision.param.value > conv->field_width.param.value)
		conv->field_width.param.value = conv->precision.param.value;
	return (conv->field_width.param.value);
}

void	ft_print_to_x(char *to_write, const t_conversion *conv)
{
	print_hexa(to_write, conv, 16, HEXADECIMAL_DIGITS);
}

int		ft_printf_len_x_maj(t_conversion *conv)
{
	return (ft_printf_len_x(conv));
}

void	ft_print_to_x_maj(char *to_write, const t_conversion *conv)
{
	print_hexa(to_write, conv, 16, HEXADECIMAL_DIGITS_CAPS);
}
