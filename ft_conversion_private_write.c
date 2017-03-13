/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_write.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:30:48 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/13 19:17:09 by mgautier         ###   ########.fr       */
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
		empty_field_width = global_start + conv->result_length;
	else
		empty_field_width = global_start;
	return ((char*)empty_field_width);
}

static void	ft_write_field_width(char *to_write, int fill, char padding)
{
	int	index;

	index = 0;
	while (index < fill)
	{
		to_write[index] = padding;
		index++;
	}
}

int			ft_write_conversion(char *to_write, const t_conversion *conv)
{
	char	*start_of_conv;
	char	*start_of_field_width;

	start_of_conv = start_actual_conv(to_write, conv);
	start_of_field_width = empty_field_width(to_write, conv);
	g_print_to_test[conv->type](start_of_conv, conv);
	ft_write_field_width(start_of_field_width,
			conv->field_width.param.value - conv->result_length,
			conv->flags[ZERO_PADDING] ? '0' : ' ');
	return (ft_get_conv_len(conv));
}
