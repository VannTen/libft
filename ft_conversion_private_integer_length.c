/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_integer_length.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 09:48:51 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/27 14:30:44 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "printf_constants.h"
#include "itoa_tools.h"
#include "libft.h"

int			count_alternate_form(const t_conversion *conv)
{
	int	alternate_form_len;

	alternate_form_len = 0;
	if (conv->flags[ALTERNATE_FORM] && has_alternate_form_hexa(conv))
		alternate_form_len = ft_strlen(HEXA_ALTERNATE_FORM);
	return (alternate_form_len);
}

void	handle_zero_padding(t_conversion *conv)
{
	if (conv->flags[ZERO_PADDING])
	{
		conv->precision.param.value = conv->field_width.param.value
			- conv->supp_length;
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
