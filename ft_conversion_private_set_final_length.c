/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_set_final_length.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:40:11 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/17 12:58:05 by mgautier         ###   ########.fr       */
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
	return (total);
}
void	set_final_conversion_length(t_conversion *conv)
{
	int	result;

	settle_incompatibilities(conv);
	result = 0;
	if (is_integer_conv(conv))
		result = set_integer_length(conv);
	else if (is_string_conv(conv))
		result = set_string_length(conv);
	if (conv->field_width.param.value <= result)
	{
		conv->field_width.param.value = result;
		conv->flags[NEGATIVE_FIELD_WIDTH] = FALSE;
	}
}
