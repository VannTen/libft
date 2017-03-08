/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_const.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:30:48 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/08 15:46:33 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "conv_write_interface.h"
#include <limits.h>

size_t			ft_get_conv_len(const t_conversion *conv)
{
	size_t	field_width;

	if (conv->field_width.value < 0)
	{
		if (conv->field_width.value == INT_MIN)
		{
			field_width = INT_MAX;
			field_width++;
		}
		else
			field_width = -conv->field_width.value;
	}
	else
		field_width = conv->field_width.value;
	return (field_width > conv->result_length ?
			field_width : conv->result_length);
}

size_t			ft_get_conv_text_len(const t_conversion *conv)
{
	return (conv->specifier_length);
}

size_t			ft_write_conversion(char *to_write, const t_conversion *conv)
{
	char	*write_conv_here;
	char	*write_field_width_here;

	write_conv_here = start_actual_conv(to_write, conv);
	write_field_width_here = empty_field_width(to_write, conv);
	g_print_to_test[conv->type](write_conv_here, conv);
	ft_write_field_width(write_field_width_here, to_fill_field_width(conv),
			conv->flags[ZERO_PADDING] ? '0' : ' ');
	return (ft_get_conv_len(conv));
}

unsigned int	ft_arg_required(const void *conversion)
{
	return (((const t_conversion*)conversion)->arg_index);
}

unsigned int	get_modifier(const t_conversion *conversion)
{
	return (conversion->length_modifier);
}
