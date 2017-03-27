/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_set_final_length.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:40:11 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/27 14:49:02 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "variadic_args_interface.h"
#include "conv_len_interface.h"
#include "printf_constants.h"
#include "libft.h"

int		set_string_length(t_conversion *conv)
{
	int total;

	total = ft_get_len_conv(conv);
	conv->precision.param.value = total;
	conv->result_length = total;
	return (total);
}

int		set_and_get_final_conversion_length(t_conversion *conv)
{
	int	result;

	settle_incompatibilities(conv);
	result = ft_get_len_conv(conv);
	if (result < 0)
		return (INVALID_CONVERSION_RESULT);
	else
		return (result + conv->preceding_length);
}

int		length_integers(t_conversion *conv, int conversion_result)
{
	int result;

	result = 0;
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
