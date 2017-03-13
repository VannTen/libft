/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_ressources.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:01:06 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/13 16:02:27 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "conversion_defs.h"
#include "bool.h"
#include <stdlib.h>

void			conversion_destroy(t_conversion *conversion)
{
	enum e_flags	index;

	if (conversion != NULL)
	{
		index = 0;
		while (index < FLAGS_NBR)
		{
			conversion->flags[index] = FALSE;
			index++;
		}
		conversion->arg_index = 0;
		conversion->field_width.param.value = 0;
		conversion->precision.param.value = 0;
		conversion->field_width.is_arg = FALSE;
		conversion->precision.is_arg = FALSE;
		conversion->length_modifier = 0;
	}
	free(conversion);
}

t_conversion	*conversion_ctor(void)
{
	t_conversion	*conversion;
	enum e_flags	index;

	conversion = malloc(sizeof(t_conversion));
	if (conversion != NULL)
	{
		index = 0;
		while (index < FLAGS_NBR)
		{
			conversion->flags[index] = FALSE;
			index++;
		}
		conversion->arg_index = 0;
		conversion->positional = FALSE;
		conversion->is_valid = TRUE;
		conversion->field_width.param.value = 0;
		conversion->precision.param.value = 0;
		conversion->field_width.is_arg = FALSE;
		conversion->precision.is_arg = FALSE;
		conversion->length_modifier = 0;
	}
	return (conversion);
}
