/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_const.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:30:48 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/07 17:16:49 by mgautier         ###   ########.fr       */
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

		if (conv->field_width.value < 0)
		{
			write_conv_here = to_write;
			write_field_width_here = to_write +
				ft_get_conv_len(conv) - conv->result_length - 1;
		}
		else
		{
			write_conv_here = to_write +
				ft_get_conv_len(conv) - conv->result_length;
			write_field_width_here = to_write;
		}
	g_print_to_test[conv->type](write_conv_here, conv);
	ft_write_field_width(write_field_width_here, conv->field_width.value,
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
