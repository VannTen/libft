/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_specifier.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 18:45:00 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/22 13:21:47 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "printf_constants.h"
#include <stdlib.h>

size_t	set_field_width(const char *conversion_specifier, size_t index,
		t_conversion *convers_specs)
{
	return (set_int_params(conversion_specifier, index,
				&convers_specs->field_width, convers_specs->format_string));
}

size_t	set_precision(const char *conversion_specifier, size_t index,
		t_conversion *convers_specs)
{
	if (conversion_specifier[index] == PRECISION_INDICATOR)
	{
		index++;
		index = set_int_params(conversion_specifier, index,
				&convers_specs->precision, convers_specs->format_string);
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
	convers_specs->length_modifier = modifier_index;
	if (modifier_index != LENGTH_MODIFIER_NBR)
		index++;
	if ((modifier_index == SHORT || modifier_index == LONG)
			&& conversion_specifier[index] == conversion_specifier[index - 1])
	{
		convers_specs->length_modifier++;
		index++;
	}
	return (index);
}

size_t	set_type_conversion(const char *conversion_specifier, size_t index,
		t_conversion *convers_specs)
{
	size_t	type_index;
	char	type;

	type_index = 0;
	while ((type_index < UNKNOWN_CONVERSION)
			&& conversion_specifier[index] != g_conv_types[type_index])
		type_index++;
	if (type_index > NO_CONVERSION && type_index < UNKNOWN_CONVERSION)
	{
		convers_specs->length_modifier = LONG;
		type = g_conv_types[type_index] - 'A' + 'a';
		type_index = 0;
		while (g_conv_types[type_index] != type)
			type_index++;
	}
	convers_specs->type = type_index;
	if (type_index != UNKNOWN_CONVERSION)
	{
		index++;
		if (convers_specs->arg_index == 0)
			convers_specs->arg_index =
				ft_request_arg(convers_specs->format_string);
	}
	return (index);
}
