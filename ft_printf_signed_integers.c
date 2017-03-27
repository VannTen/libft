/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_signed_integers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 08:55:33 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/27 14:26:23 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "variadic_args_interface.h"
#include "itoa_tools.h"

int		count_signedness(const t_conversion *conv)
{
	if (conv->flags[ALWAYS_SIGN] || conv->flags[BLANK] ||
			is_signed_negative(conv->arg))
		return (1);
	else
		return (0);
}

int		write_signedness(char *to_write, const t_conversion *conv)
{
	if (is_signed_negative(conv->arg))
		*to_write = '-';
	else if (conv->flags[ALWAYS_SIGN])
		*to_write = '+';
	else if (conv->flags[BLANK])
		*to_write = ' ';
	else
		return (0);
	return (1);
}

int		ft_printf_len_di(t_conversion *conv)
{
	int result;
	int	conversion_result;

	result = 0;
	conversion_result = itoa_len_signed(ft_var_signed_integers(conv->arg), 10);
	conv->result_length = conversion_result;
	conv->supp_length = count_signedness(conv);
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

void	ft_print_to_di(char *to_write, const t_conversion *conv)
{
	int index;

	index = 0;
	if (!conv->flags[NEGATIVE_FIELD_WIDTH])
		index += ft_write_field_width(to_write, conv->field_width.param.value
				- conv->precision.param.value - count_signedness(conv),
				conv->flags[ZERO_PADDING] ? '0' : ' ');
	index += write_signedness(to_write + index, conv);
	index += ft_write_precision(to_write + index, conv);
	itoa_write_signed(to_write + index + conv->result_length - 1,
			ft_var_signed_integers(conv->arg), 10, DECIMAL_DIGITS);
	index += conv->result_length;
	if (conv->flags[NEGATIVE_FIELD_WIDTH])
		index += ft_write_field_width(to_write + index,
				conv->field_width.param.value
				- conv->precision.param.value - count_signedness(conv),
				conv->flags[ZERO_PADDING] ? '0' : ' ');
}
