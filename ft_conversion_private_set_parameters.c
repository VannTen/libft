/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_set_parameters.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 13:45:19 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/13 18:42:20 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "conv_len_interface.h"
#include "bool.h"
#include <stdlib.h>

t_bool		set_one_flag(const char *conversion_specifier, int index,
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

void		set_conversion_spec_len(t_conversion *conv, int index)
{
	conv->specifier_length = index;
}

static void	handle_negative_field_width(t_conversion *conv)
{
	if (conv->field_width.param.value < 0)
	{
		conv->flags[NEGATIVE_FIELD_WIDTH] = TRUE;
		conv->field_width.param.value = -conv->field_width.param.value;
	}
	if (conv->field_width.param.value <= conv->result_length)
		conv->field_width.param.value = conv->result_length;
	if (conv->flags[NEGATIVE_FIELD_WIDTH])
		conv->flags[ZERO_PADDING] = FALSE;
}

void		set_conversion_result_length(t_conversion *conv)
{
	int	field_width_result;

	field_width_result = g_print_len[conv->type](conv);
	handle_negative_field_width(conv);
	if (conv->field_width.param.value < field_width_result)
		conv->field_width.param.value = field_width_result;
}
