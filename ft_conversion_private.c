/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 13:45:19 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/01 15:47:48 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"

t_bool			set_one_flag(const char *conversion_specifier, size_t index,
		t_conversion *convers_specs)
{
	size_t	index_flags;

	index_flags = 0;
	while (index_flags < FLAGS_NBR
			&& conversion_specifier[index] != g_flags[index_flags])
		index_flags++;
	if (index_flags != FLAGS_NBR)
	{
		convers_specs->flags[index_flags] = TRUE;
		return (TRUE);
	}
	else
		return (FALSE);
}

size_t			set_positional_arg(const char *conversion_text,
		size_t index, t_conversion *convers_specs)
{
	return (ft_set_arg_positional(conversion_text, index,
				&convers_specs->arg_index));
}

t_conversion	*conversion_ctor(void)
{
	t_conversion	*conversion;
	size_t			index;

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
		conversion->field_width.value = 0;
		conversion->precision.value = 0;
		conversion->field_width.is_arg = FALSE;
		conversion->precision.is_arg = FALSE;
		conversion->length_modifier = 0;
	}
	return (conversion);
}

void			set_conversion_spec_len(t_conversion *conv, size_t index)
{
	conv->specifier_length = index;
}

void			set_conversion_result_length(t_conversion *conv, size_t index)
{
	conv->result_length = index;
}
