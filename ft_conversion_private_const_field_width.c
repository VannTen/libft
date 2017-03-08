/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_const_field_width.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 15:06:24 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/08 15:52:16 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"

char	*start_actual_conv(const char *global_start, const t_conversion *conv)
{
	const char	*start_actual_conv;

	if (conv->field_width.value < 0)
		start_actual_conv = global_start;
	else
		start_actual_conv =
			global_start + conv->field_width.value - conv->result_length;
	return ((char*)start_actual_conv);
}

char	*empty_field_width(const char *global_start, const t_conversion *conv)
{
	const char	*empty_field_width;

	if (conv->field_width.value < 0)
		empty_field_width = global_start - conv->field_width.value - 1;
	else
		empty_field_width = global_start;
	return ((char*)empty_field_width);
}

int		to_fill_field_width(const t_conversion *conv)
{
	int	rest_to_fill;

	if (conv->field_width.value < 0)
		rest_to_fill = conv->field_width.value + conv->result_length;
	else
		rest_to_fill = conv->field_width.value - conv->result_length;
	return (rest_to_fill);
}

