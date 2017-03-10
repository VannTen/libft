/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 13:45:19 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/10 18:20:14 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "conv_len_interface.h"
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

t_bool			set_one_flag(const char *conversion_specifier, int index,
		t_conversion *convers_specs)
{
	enum e_flags		index_flags;
	static const char	flags[] = "#0- +'";

	index_flags = 0;
	while (index_flags < FLAGS_NBR
			&& conversion_specifier[index] != flags[index_flags])
		index_flags++;
	if (index_flags != FLAGS_NBR)
	{
		convers_specs->flags[index_flags] = TRUE;
		return (TRUE);
	}
	else
		return (FALSE);
}

void			set_conversion_spec_len(t_conversion *conv, int index)
{
	conv->specifier_length = index;
}

void			set_conversion_result_length(t_conversion *conv)
{
	conv->result_length = g_print_len[conv->type](conv);
}
