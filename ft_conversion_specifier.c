/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_specifier.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 18:45:00 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/06 12:04:32 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "printf_constants.h"
#include <stdlib.h>

size_t	set_field_width(const char *conversion_specifier, size_t index,
		t_conversion *convers_specs, t_format_string *fmt)
{
	return (index + set_int_params(conversion_specifier + index,
				&convers_specs->field_width, fmt));
}

size_t	set_precision(const char *conversion_specifier, size_t index,
		t_conversion *convers_specs, t_format_string *fmt)
{
	if (conversion_specifier[index] == PRECISION_INDICATOR)
	{
		index++;
		index += set_int_params(conversion_specifier + index,
				&convers_specs->precision, fmt);
	}
	return (index);
}

size_t	set_length_modifier(const char *conversion_specifier,
		size_t index, t_conversion *convers_specs)
{
	size_t	modifier_index;

	modifier_index = 0;
	while (modifier_index < LENGTH_MODIFIER_NBR
			&& g_length_modifier[modifier_index] != conversion_specifier[index])
		modifier_index++;
	if (modifier_index != LENGTH_MODIFIER_NBR)
	{
		convers_specs->length_modifier = modifier_index;
		index++;
	}
	else
		convers_specs->length_modifier = NONE;
	if ((modifier_index == SHORT || modifier_index == LONG)
			&& conversion_specifier[index] == conversion_specifier[index - 1])
	{
		modifier_index == LONG ?
			convers_specs->length_modifier++ : convers_specs->length_modifier--;
		index++;
	}
	return (index);
}

static t_conv_type	get_conv_type(const char type_specifier, t_conversion *conv)
{
	t_conv_type	type_index;
	char		type;

	type_index = 0;
	while ((type_index < UNKNOWN_CONVERSION)
			&& type_specifier != g_conv_types[type_index])
		type_index++;
	if (type_index > NO_CONVERSION && type_index < UNKNOWN_CONVERSION)
	{
		conv->length_modifier = LONG;
		type = g_conv_types[type_index] - 'A' + 'a';
		type_index = 0;
		while (g_conv_types[type_index] != type)
			type_index++;
	}
	return (type_index);
}

size_t	set_type_conversion(const char *conversion_specifier, size_t index,
		t_conversion *convers_specs, t_format_string *fmt)
{
	t_conv_type	type_index;

	type_index = get_conv_type(conversion_specifier[index], convers_specs);
	if (type_index != UNKNOWN_CONVERSION)
	{
		index++;
		if (convers_specs->arg_index == 0)
			convers_specs->arg_index = ft_request_arg(fmt);
	}
	else
		type_index = UNSUPPORTED_CONVERSION;
	convers_specs->type = type_index;
	return (index);
}
