/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_write.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:30:48 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/14 17:10:07 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "conv_write_interface.h"
#include "printf_constants.h"
#include "libft.h"

static int	ft_no_field_width_length(const t_conversion *conv)
{
	return (conv->precision.param.value + ft_flags_len(conv));
}
static char	*start_actual_conv(const char *global_start, const t_conversion *conv)
{
	const char	*start_actual_conv;

	if (conv->flags[NEGATIVE_FIELD_WIDTH])
		start_actual_conv = global_start;
	else
		start_actual_conv =
			global_start + conv->field_width.param.value - ft_no_field_width_length(conv);
	return ((char*)start_actual_conv);
}

static char	*empty_field_width(const char *global_start, const t_conversion *conv)
{
	const char	*empty_field_width;

	if (conv->flags[NEGATIVE_FIELD_WIDTH])
		empty_field_width = global_start + ft_no_field_width_length(conv);
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

static int		ft_write_precision(char *to_write, const t_conversion *conv)
{
	int	leading_zeros;
	int index;

	index = 0;
	if (conv->precision.param.value != NO_PRECISION)
		leading_zeros = conv->precision.param.value - conv->result_length;
	else
		leading_zeros = 0;
	while (index < leading_zeros)
	{
		to_write[index] = '0';
		index++;
	}
	return (leading_zeros);
}

static void		ft_write_without_field_width(char *to_write, const t_conversion *conv)
{
	int index;

	index = 0;
	index += ft_write_flags(to_write, conv);
	index += ft_write_precision(to_write + index, conv);
	g_print_to_test[conv->type](to_write + index, conv);
}

int			ft_write_conversion(char *to_write, const t_conversion *conv)
{
	char	*start_of_conv;
	char	*start_of_field_width;

	start_of_conv = start_actual_conv(to_write, conv);
	start_of_field_width = empty_field_width(to_write, conv);
	ft_write_without_field_width(start_of_conv, conv);
	ft_write_field_width(start_of_field_width,
			conv->field_width.param.value - ft_no_field_width_length(conv),
			conv->flags[ZERO_PADDING] ? '0' : ' ');
	return (conv->field_width.param.value);
}
