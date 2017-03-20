/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_set_parameters.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 13:45:19 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/20 14:55:59 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "flags_defs.h"
#include "printf_constants.h"
#include "bool.h"

void	set_conversion_spec_len(t_conversion *conv, int index)
{
	conv->specifier_length = index;
}

void	settle_incompatibilities(t_conversion *conv)
{
	if (conv->field_width.param.value < 0)
	{
		conv->flags[NEGATIVE_FIELD_WIDTH] = TRUE;
		conv->field_width.param.value = -conv->field_width.param.value;
	}
	if ((is_numeric(conv) && conv->precision.param.value != NO_PRECISION)
			|| (conv->flags[NEGATIVE_FIELD_WIDTH]))
		conv->flags[ZERO_PADDING] = FALSE;
	if (conv->flags[ALWAYS_SIGN])
		conv->flags[BLANK] = FALSE;
}
