/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_positions_write.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:16:50 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/20 14:56:31 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"

char	*start_of_conv_is(const char *global_start, const t_conversion *conv)
{
	const char	*start_actual_conv;

	if (conv->flags[NEGATIVE_FIELD_WIDTH])
		start_actual_conv = global_start;
	else
		start_actual_conv = global_start +
			conv->field_width.param.value - ft_no_field_width_length(conv);
	return ((char*)start_actual_conv);
}

char	*start_of_field_width_is(const char *global_start,
		const t_conversion *conv)
{
	const char	*empty_field_width;

	if (conv->flags[NEGATIVE_FIELD_WIDTH])
		empty_field_width = global_start + ft_no_field_width_length(conv);
	else
		empty_field_width = global_start;
	return ((char*)empty_field_width);
}
