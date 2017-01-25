/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 18:03:31 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/25 18:32:33 by mgautier         ###   ########.fr       */
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

	conversion = malloc(sizeof(t_conversion));
	if (conversion != NULL)
	{
		conversion->flags.alternate_form = FALSE;
		conversion->flags.zero_padding = FALSE;
		conversion->flags.inverse_padding = FALSE;
		conversion->flags.blank_before_signed = FALSE;
		conversion->flags.explicit_signed = FALSE;
		conversion->flags.thousands_grouping = FALSE;
		conversion->field_width = 0;
		conversion->precision = 0;
		conversion->length_modifier = 0;
	}
	return (conversion);
}

t_conversion		*parser(char **conversion_begin)
{
	t_conversion	*conversion;

	conversion = ctor();
	if (conversion == NULL)
		return (NULL);
}
