/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_and_strings.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 13:07:32 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/21 17:10:21 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "length_modifier_defs.h"
#include "variadic_args_interface.h"
#include "printf_constants.h"
#include "wide_char_interface.h"
#include "libft.h"
#include <wchar.h>

int		ft_printf_len_c(const t_conversion *conv)
{
	if (conv->length_modifier == LONG)
		return (ft_wctomb_len(ft_wint_type(conv->arg)));
	else
		return (1);
}

int		ft_printf_len_s(const t_conversion *conv)
{
	if (conv->length_modifier == LONG)
		return (ft_wcstrntomb_len(ft_pointer(conv->arg),
				conv->precision.param.value));
	if (conv->precision.param.value != NO_PRECISION)
		return (ft_strnlen(ft_pointer(conv->arg), conv->precision.param.value));
	else
		return (ft_strlen(ft_pointer(conv->arg)));
}

void	ft_print_to_c(char *to_write, const t_conversion *conv)
{
	if (conv->length_modifier == LONG)
		ft_wctomb(to_write, ft_wint_type(conv->arg));
	else
		*to_write = (char)ft_var_signed_integers(conv->arg);
}

void	ft_print_to_s(char *to_write, const t_conversion *conv)
{
	if (conv->length_modifier == LONG)
		ft_wcstrntomb_write(to_write, ft_pointer(conv->arg),
				conv->precision.param.value);
	else
		ft_strncpy(to_write, ft_pointer(conv->arg),
				conv->precision.param.value);
}
