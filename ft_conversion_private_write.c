/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_write.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:30:48 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/22 14:06:44 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "conv_write_interface.h"
#include "printf_constants.h"
#include "libft.h"

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

static int	ft_write_precision(char *to_write, const t_conversion *conv)
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

static void	ft_write_conv(char *to_write, const t_conversion *conv)
{
	int						index;

	index = 0;
	if (is_integer_conv(conv))
	{
		index += ft_write_integer_conv(to_write, conv);
		index += ft_write_precision(to_write + index, conv);
	}
	ft_select_writer_conv(to_write + index, conv);
}

int			ft_write_conversion(char *to_write, const t_conversion *conv)
{
	if (!(conv->field_width.param.value IS_INVALID_CONVERSION_RESULT))
	{
		ft_write_conv(start_of_conv_is(to_write, conv), conv);
		ft_write_field_width(start_of_field_width_is(to_write, conv),
				conv->field_width.param.value - ft_no_field_width_length(conv),
				conv->flags[ZERO_PADDING] ? '0' : ' ');
	}
	return (conv->field_width.param.value);
}
