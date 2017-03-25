/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_integer_length.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 09:48:51 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/25 01:29:18 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "printf_constants.h"
#include "libft.h"

int			count_alternate_form(const t_conversion *conv)
{
	int	alternate_form_len;

	alternate_form_len = 0;
	if (conv->flags[ALTERNATE_FORM])
	{
		if (has_alternate_form_hexa(conv))
			alternate_form_len = ft_strlen(HEXA_ALTERNATE_FORM);
		else if (conv->type == O)
			alternate_form_len = has_no_null_value(conv->arg) ? 1 : 0;
	}
	return (alternate_form_len);
}

static void	handle_zero_padding(t_conversion *conv)
{
	if (conv->flags[ZERO_PADDING])
	{
		conv->precision.param.value = conv->field_width.param.value
			- (count_alternate_form(conv) + count_signedness(conv));
	}
}

static int	total_before_padding(t_conversion *conv)
{
	int				result;

	if (conv->precision.param.value == NO_PRECISION)
		conv->precision.param.value = INTEGER_DEFAULT_PRECISION;
	result = ft_get_len_conv(conv);
	conv->result_length = result;
	if (conv->precision.param.value <= result)
		conv->precision.param.value = result +
			(conv->type == O ? count_alternate_form(conv) : 0);
	else
		result = conv->precision.param.value;
	result += count_signedness(conv) + count_alternate_form(conv);
	return (result);
}

int			set_integer_length(t_conversion *conv)
{
	handle_zero_padding(conv);
	return (total_before_padding(conv));
}
