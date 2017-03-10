/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_const.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:30:48 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/10 13:52:42 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "conv_write_interface.h"
#include <limits.h>

int			ft_get_conv_len(const t_conversion *conv)
{
	int	field_width;

	if (conv->field_width.param.value < 0)
	{
		if (conv->field_width.param.value == INT_MIN)
		{
			field_width = INT_MAX;
			field_width++;
		}
		else
			field_width = -conv->field_width.param.value;
	}
	else
		field_width = conv->field_width.param.value;
	return (field_width > conv->result_length ?
			field_width : conv->result_length);
}

int			ft_get_conv_text_len(const t_conversion *conv)
{
	return (conv->specifier_length);
}

int			ft_write_conversion(char *to_write, const t_conversion *conv)
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

size_t	ft_arg_required(const void *conversion)
{
	return (((const t_conversion*)conversion)->arg_index);
}

size_t	get_modifier(const t_conversion *conversion)
{
	return (conversion->length_modifier);
}
