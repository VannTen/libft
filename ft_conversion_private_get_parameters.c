/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_get_parameters.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:12:46 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/13 16:22:16 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include <limits.h>

int		ft_get_conv_len(const t_conversion *conv)
{
	int	field_width;

	if (conv->field_width.param.value < 0)
	{
		if (conv->field_width.param.value == INT_MIN)
		{
			field_width = INT_MAX;
			field_width++;
		}
		else
			field_width = -conv->field_width.param.value;
	}
	else
		field_width = conv->field_width.param.value;
	return (field_width > conv->result_length ?
			field_width : conv->result_length);
}

int		ft_get_conv_text_len(const t_conversion *conv)
{
	return (conv->specifier_length);
}

size_t	ft_arg_required(const void *conversion)
{
	return (((const t_conversion*)conversion)->arg_index);
}

size_t	get_modifier(const t_conversion *conversion)
{
	return (conversion->length_modifier);
}

size_t		bigger_arg_required(const t_conversion *conv)
{
	size_t max;

	max = conv->arg_index;
	if (conv->field_width.is_arg)
		max = max > conv->field_width.param.arg_index ?
			max : conv->field_width.param.arg_index;
	if (conv->precision.is_arg)
		max = max > conv->precision.param.arg_index ?
			max : conv->precision.param.arg_index;
	return (max);
}
