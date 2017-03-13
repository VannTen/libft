/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_write.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:30:48 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/13 16:32:57 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "conv_write_interface.h"

static char	*start_actual_conv(const char *global_start, const t_conversion *conv)
{
	const char	*start_actual_conv;

	if (conv->flags[NEGATIVE_FIELD_WIDTH])
		start_actual_conv = global_start;
	else
		start_actual_conv =
			global_start + conv->field_width.param.value - conv->result_length;
	return ((char*)start_actual_conv);
}

static char	*empty_field_width(const char *global_start, const t_conversion *conv)
{
	const char	*empty_field_width;

	if (conv->flags[NEGATIVE_FIELD_WIDTH])
		empty_field_width = global_start - conv->field_width.param.value - 1;
	else
		empty_field_width = global_start;
	return ((char*)empty_field_width);
}

static int	to_fill_field_width(const t_conversion *conv)
{
	int	rest_to_fill;

	if (conv->flags[NEGATIVE_FIELD_WIDTH])
		rest_to_fill = conv->field_width.param.value + conv->result_length;
	else
		rest_to_fill = conv->field_width.param.value - conv->result_length;
	return (rest_to_fill);
}

static void	ft_write_field_width(char *to_write, int fill, char padding)
{
	int	add;

	add = fill < 0 ? 1 : -1;
	while (fill != 0)
	{
		fill += add;
		to_write[fill] = padding;
	}
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
