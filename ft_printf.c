/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:03:31 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/30 15:10:07 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

/*
** Constructor for the conversion struct
**
** Allocates and initializes to default values the optionnal parameters
** of a conversion.
*/

static t_conversion	*ctor(t_format_string *format_string)
{
	t_conversion	*conversion;
	size_t			index;

	conversion = malloc(sizeof(t_conversion));
	if (conversion != NULL)
	{
		index = 0;
		while (index < NBR_OF_FLAGS)
		{
			conversion->flags[index] = FALSE;
			index++;
		}
		conversion->field_width.value = 0;
		conversion->precision.value = 0;
		conversion->field_width.is_arg = FALSE;
		conversion->precision.is_arg = FALSE;
		conversion->length_modifier = 0;
		conversion->format_string = format_string;
	}
	return (conversion);
}

size_t		parser(const char *conversion_text, size_t index
							t_format_string *format_string)
{
	t_conversion	*conversion;

	conversion = ctor(format_string);
	if (conversion == NULL)
		return (NULL);
	while (index_functions < PARAMS_NBR)
	{
		index = params[index_functions](conversion_text, index, conversion);
		index_functions++;
	}
	/*
	index+= ft_set_arg_positional(conversion_text, conversion);
	set_flags(conversion_text, conversion);
	set_field_width(conversion_text, conversion);
	set_precision(conversion_text, conversion);
	set_length_modifier(conversion_text, conversion);
	set_type_conversion(conversion_text, conversion);
	*/
	f_fifo_add(format_string->conversion_list, conversion);
	return (index);
}
