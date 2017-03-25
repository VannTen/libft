/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 10:57:31 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/25 12:19:06 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "itoa_tools.h"
#include "libft.h"

int	ft_printf_len_p(t_conversion *conv)
{
	int result;
	int alt_result;

	if (conv->flags[ZERO_PADDING])
		conv->precision.param.value =
			conv->field_width.param.value - ft_strlen(HEXA_ALTERNATE_FORM);
	result = itoa_len_unsigned(ft_var_unsigned_integers(conv->arg), 16);
	conv->result_length = result;
	if (result > conv->precision.param.value)
		conv->precision.param.value = result;
	alt_result = conv->precision.param.value + ft_strlen(HEXA_ALTERNATE_FORM);
	if (alt_result > conv->field_width.param.value)
		conv->field_width.param.value = alt_result;
	return (conv->field_width.param.value);
}

void	ft_print_to_p(char *to_write, const t_conversion *conv)
{
	int index;

	index = 0;
	if (!conv->flags[NEGATIVE_FIELD_WIDTH])
		index += ft_write_field_width(to_write, conv->field_width.param.value
				- conv->precision.param.value - ft_strlen(HEXA_ALTERNATE_FORM),
				conv->flags[ZERO_PADDING] ? '0' : ' ');
	ft_strcpy(to_write + index, HEXA_ALTERNATE_FORM);
	index += ft_strlen(HEXA_ALTERNATE_FORM);
	index += ft_write_precision(to_write + index, conv);
	itoa_write_unsigned(to_write + index + conv->result_length - 1,
			ft_var_unsigned_integers(conv->arg), 16, HEXADECIMAL_DIGITS);
	if (conv->flags[NEGATIVE_FIELD_WIDTH])
		index += ft_write_field_width(to_write + index,
				conv->field_width.param.value -
				conv->precision.param.value - ft_strlen(HEXA_ALTERNATE_FORM),
				' ');
}
