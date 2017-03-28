/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 13:07:32 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/28 10:42:34 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "length_modifier_defs.h"
#include "variadic_args_interface.h"
#include "printf_constants.h"
#include "wide_char_interface.h"
#include "libft.h"
#include <wchar.h>

static int	len_s(const t_conversion *conv)
{
	int result;

	if (conv->precision.param.value != NO_PRECISION)
		result = ft_strnlen(ft_pointer(conv->arg),
				conv->precision.param.value);
	else
		result = ft_strlen(ft_pointer(conv->arg));
	return (result);
}

static int	len_wides(const t_conversion *conv)
{
	return (ft_wcstrntomb_len(ft_pointer(conv->arg),
				conv->precision.param.value));
}

int			ft_printf_len_s(t_conversion *conv)
{
	return (strings_chars_length(conv, &len_s, &len_wides));
}

static int	s_writer(char *to_write, const t_conversion *conv)
{
	int index;

	index = 0;
	if (conv->length_modifier == LONG)
		index = ft_wcstrntomb_write(to_write, ft_pointer(conv->arg),
				conv->precision.param.value);
	else
	{
		ft_strncpy(to_write, ft_pointer(conv->arg),
				conv->precision.param.value);
		index = conv->precision.param.value;
	}
	return (index);
}

void		ft_print_to_s(char *to_write, const t_conversion *conv)
{
	write_whole_conv_strings_chars(to_write, conv, &s_writer);
}
