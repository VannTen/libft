/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_set_final_length.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:40:11 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/14 15:53:43 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "variadic_args_interface.h"
#include "conv_len_interface.h"
#include "printf_constants.h"
#include "libft.h"

int	ft_flags_len(const t_conversion *conv)
{
	int	flags_len;

	flags_len = 0;
	if (conv->flags[ALTERNATE_FORM])
	{
		if (conv->type == X || conv->type == X_MAJ)
			flags_len += ft_strlen(HEXA_ALTERNATE_FORM);
	}
	if (conv->flags[ALWAYS_SIGN] && is_signed_positive(conv->arg))
		flags_len++;
	else if (conv->flags[BLANK] && is_signed_positive(conv->arg))
		flags_len++;
	return (flags_len);
}

static void	handle_negative_field_width(t_conversion *conv)
{
	if (conv->field_width.param.value < 0)
	{
		conv->flags[NEGATIVE_FIELD_WIDTH] = TRUE;
		conv->field_width.param.value = -conv->field_width.param.value;
	}
	if (conv->field_width.param.value <=
			conv->precision.param.value + ft_flags_len(conv))
		conv->flags[NEGATIVE_FIELD_WIDTH] = FALSE;
	if (conv->flags[NEGATIVE_FIELD_WIDTH])
		conv->flags[ZERO_PADDING] = FALSE;
}

static int	set_final_precision(t_conversion *conv)
{
	int result;

	result = g_print_len[conv->type](conv);
	conv->result_length = result;
	if (conv->precision.param.value < result)
		conv->precision.param.value = result;
	else
		result = conv->precision.param.value;
	return (result + ft_flags_len(conv));
}

static void	set_final_field_width(t_conversion *conv)
{
	int	no_field_width_result;

	no_field_width_result = set_final_precision(conv);
	handle_negative_field_width(conv);
	if (conv->field_width.param.value < no_field_width_result)
		conv->field_width.param.value = no_field_width_result;
}

void		set_final_conversion_length(t_conversion *conv)
{
	set_final_field_width(conv);
}
