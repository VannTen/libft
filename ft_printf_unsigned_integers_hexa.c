/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_integers_hexa.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 19:02:34 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/27 14:39:17 by mgautier         ###   ########.fr       */
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
				- conv->precision.param.value - count_alternate_form(conv),
				conv->flags[ZERO_PADDING] ? '0' : ' ');
	if (conv->flags[ALTERNATE_FORM] && conv->result_length != 0)
	{
		ft_strcpy(to_write + index, conv->type == X ?
				HEXA_ALTERNATE_FORM : HEXA_MAJ_ALTERNATE_FORM);
		index += ft_strlen(HEXA_ALTERNATE_FORM);
	}
	index += ft_write_precision(to_write + index, conv);
	itoa_write_unsigned(to_write + index + conv->result_length - 1,
			ft_var_unsigned_integers(conv->arg), base, base_digits);
	index += conv->result_length;
	if (conv->flags[NEGATIVE_FIELD_WIDTH])
		index += ft_write_field_width(to_write + index,
				conv->field_width.param.value -
				conv->precision.param.value - count_alternate_form(conv),
				' ');
}

int		ft_printf_len_x(t_conversion *conv)
{
	int result;
	int conversion_result;

	result = 0;
	conversion_result = itoa_len_unsigned(ft_var_unsigned_integers(conv->arg), 16);
	conv->result_length = conversion_result;
	conv->supp_length = count_alternate_form(conv);
	handle_zero_padding(conv);
	if (conversion_result > conv->precision.param.value)
		conv->precision.param.value = conversion_result;
	else
		conversion_result = conv->precision.param.value;
	result = conversion_result + conv->supp_length;
	if (result > conv->field_width.param.value)
		conv->field_width.param.value = result;
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
