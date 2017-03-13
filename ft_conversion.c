/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 12:23:57 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/10 15:57:17 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_string_interface.h"
#include "conversion_interface.h"
#include "ft_set_params.h"
#include <stdlib.h>

int	ft_add_conversion(const char *conv_text, t_format_string *fmt)
{
	int				index;
	t_conversion	*conversion;

	index = 1;
	conversion = conversion_ctor();
	if (conversion == NULL)
		return (0);
	index += set_positional_arg(conv_text + index, conversion);
	index += set_flags(conv_text + index, conversion);
	index += set_field_width(conv_text + index, conversion, fmt);
	index += set_precision(conv_text + index, conversion, fmt);
	index += set_length_modifier(conv_text + index, conversion);
	index += set_type_conversion(conv_text + index, conversion, fmt);
	set_conversion_spec_len(conversion, index);
	if (!f_add_conv_to_fmt(fmt, conversion, index))
		return (0);
	return (index);
}
