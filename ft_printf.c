/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:03:31 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/27 19:33:08 by mgautier         ###   ########.fr       */
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

static t_conversion	*ctor(void)
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
		conversion->field_width = 0;
		conversion->precision = 0;
		conversion->length_modifier = 0;
	}
	return (conversion);
}

t_conversion		*parser(char **conversion_text)
{
	t_conversion	*conversion;

	conversion = ctor();
	if (conversion == NULL)
		return (NULL);
	set_arg(conversion_text, conversion);
	set_flags(conversion_text, conversion);
	set_field_width(conversion_text, conversion);
	set_precision(conversion_text, conversion);
	set_length_modifier(conversion_text, conversion);
	set_type_conversion(conversion_text, conversion);
	return (conversion);
}
