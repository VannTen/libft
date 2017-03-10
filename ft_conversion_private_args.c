/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_args.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:09:15 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/10 17:45:27 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "bool.h"

void	ft_conv_attribute_arg(t_conversion *conv, t_var_arg *arg_array)
{
	if (conv->field_width.is_arg)
		conv->field_width.param.value =
			ft_get_int(ft_get_address(
						arg_array, conv->field_width.param.arg_index));
	if (conv->precision.is_arg)
		conv->precision.param.value =
			ft_get_int(ft_get_address(
						arg_array, conv->precision.param.arg_index));
	conv->arg = ft_get_address(arg_array, conv->arg_index);
}

int	set_positional_arg(const char *conversion_text, t_conversion *convers_specs)
{
	int	index;

	index = ft_set_arg_positional(conversion_text,
			&convers_specs->arg_index);
	if (index != 0)
		convers_specs->positional = TRUE;
	return (index);
}

size_t		bigger_arg_required(const t_conversion *conv)
{
	size_t max;

	max = conv->arg_index;
	if (conv->field_width.is_arg)
		max = max > conv->field_width.param.arg_index ?
			max : conv->field_width.param.arg_index;
	if (conv->precision.is_arg)
		max = max > conv->precision.param.arg_index ?
			max : conv->precision.param.arg_index;
	return (max);
}

void	ft_normalize_args(t_conversion *conv)
{
	if (conv->arg_index != 0)
		conv->arg_index--;
	else
		conv->is_valid = FALSE;
	if (conv->field_width.is_arg)
	{
		if (conv->field_width.param.arg_index != 0)
			conv->field_width.param.arg_index--;
		else
		{
			conv->field_width.is_arg = FALSE;
			conv->field_width.param.value = 0;
		}
	}
	if (conv->field_width.is_arg)
	{
		if (conv->field_width.param.arg_index != 0)
			conv->field_width.param.arg_index--;
		else
		{
			conv->field_width.is_arg = FALSE;
			conv->field_width.param.value = 0;
		}
	}
}

void	ft_post_process_conv(t_conversion *conv)
{
	if (conv->field_width.param.value < 0)
	{
		conv->flags[NEGATIVE_FIELD_WIDTH] = TRUE;
		conv->field_width.param.value = - conv->field_width.param.value;
	}
	if (conv->flags[NEGATIVE_FIELD_WIDTH])
		conv->flags[ZERO_PADDING] = FALSE;
}
