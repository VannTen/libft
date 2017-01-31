/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_specifier.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 18:45:00 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/31 17:45:29 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_types.h"
# include "ft_conversion_specifier.h"
# include "ft_argument.h"
# include "ft_printf.h"
# include "libft.h"
# include <stdlib.h>

size_t			set_field_width(const char *conversion_specifier, size_t index,
		t_conversion *convers_specs)
{
	return (set_int_args(conversion_specifier, index,
				&convers_specs->field_width, convers_specs->format_string));
}

size_t			set_precision(const char *conversion_specifier, size_t index,
		t_conversion *convers_specs)
{
	if (conversion_specifier[index] == PRECISION_INDICATOR)
	{
		index++;
		index = set_int_args(conversion_specifier, index,
				&convers_specs->precision, convers_specs->format_string);
	}
	return (index);
}

size_t			set_length_modifier(const char *conversion_specifier,
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
	if ((modifier_index == SHORT || modifier_index == LONG)
			&& conversion_specifier[index] == conversion_specifier[index - 1])
	{
		convers_specs->length_modifier++;
		index++;
	}
	return (index);
}

size_t		set_type_conversion(const char *conversion_specifier, size_t index,
		t_conversion *convers_specs)
{
	size_t	type_index;

	type_index = 0;
	while ((type_index < UNKNOWN_CONVERSION)
			&& conversion_specifier[index] != g_types[type_index])
		type_index++;
	convers_specs->type = type_index;
	if (type_index != UNKNOWN_CONVERSION)
	{
		index++;
		if (convers_specs->arg_index == 0)
		{
			convers_specs->format_string->arg_count++;
			convers_specs->arg_index =
				convers_specs->format_string->arg_count;
		}
	}
	return (index);
}
