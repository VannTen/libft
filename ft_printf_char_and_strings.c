/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_and_strings.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 13:07:32 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/26 21:06:44 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "length_modifier_defs.h"
#include "variadic_args_interface.h"
#include "printf_constants.h"
#include "wide_char_interface.h"
#include "libft.h"
#include <wchar.h>

int		ft_printf_len_c(t_conversion *conv)
{
	int result;

	if (conv->length_modifier == LONG)
		result = ft_wctomb_len(ft_wint_type(conv->arg));
	else
		result = 1;
	conv->result_length = result;
	if (result > conv->precision.param.value &&
			conv->precision.param.value != NO_PRECISION)
		conv->precision.param.value = 0;
	else
		conv->precision.param.value = result;
	if (conv->precision.param.value > conv->field_width.param.value)
		conv->field_width.param.value = conv->precision.param.value;
	return (conv->field_width.param.value);
}

int		ft_printf_len_s(const t_conversion *conv)
{
	if (conv->length_modifier == LONG)
		return (ft_wcstrntomb_len(ft_pointer(conv->arg),
					conv->precision.param.value));
	if (conv->precision.param.value != NO_PRECISION)
		return (ft_strnlen(ft_pointer(conv->arg), conv->precision.param.value));
	else
		return (ft_strlen(ft_pointer(conv->arg)));
}

void	ft_print_to_c(char *to_write, const t_conversion *conv)
{
	int index;

	index = 0;
	if (!conv->flags[NEGATIVE_FIELD_WIDTH])
		index += ft_write_field_width(to_write, conv->field_width.param.value
				- conv->precision.param.value,
				conv->flags[ZERO_PADDING] ? '0' : ' ');
	if (conv->length_modifier == LONG)
		index += ft_wctomb_write(to_write + index,
				ft_wint_type(conv->arg), conv->precision.param.value);
	else
	{
		to_write[index] = (char)ft_var_signed_integers(conv->arg);
		index++;
	}
	if (conv->flags[NEGATIVE_FIELD_WIDTH])
		index += ft_write_field_width(to_write + index,
				conv->field_width.param.value - conv->precision.param.value,
				conv->flags[ZERO_PADDING] ? '0' : ' ');
}

void	ft_print_to_s(char *to_write, const t_conversion *conv)
{
	if (conv->length_modifier == LONG)
		ft_wcstrntomb_write(to_write, ft_pointer(conv->arg),
				conv->precision.param.value);
	else
		ft_strncpy(to_write, ft_pointer(conv->arg),
				conv->precision.param.value);
}
