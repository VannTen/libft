/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_private_args.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:09:15 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/02 16:10:22 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"

void			ft_conv_attribute_arg(t_conversion *conv, t_var_arg *arg_array)
{
	if (conv->field_width.is_arg)
		conv->field_width.value =
			ft_get_int(ft_get_address(arg_array, conv->field_width.value));
	if (conv->precision.is_arg)
		conv->precision.value =
			ft_get_int(ft_get_address(arg_array, conv->precision.value));
	conv->arg = ft_get_address(arg_array, conv->arg_index);
}

size_t			set_positional_arg(const char *conversion_text,
		size_t index, t_conversion *convers_specs)
{
	return (ft_set_arg_positional(conversion_text, index,
				&convers_specs->arg_index));
}
