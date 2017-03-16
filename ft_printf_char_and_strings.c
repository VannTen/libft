/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_and_strings.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 13:07:32 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/16 16:49:34 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "variadic_args_interface.h"
#include "printf_constants.h"
#include "libft.h"

int	ft_printf_len_c(const t_conversion *conv)
{
	(void)conv;
	return (1);
}

int	ft_printf_len_s(const t_conversion *conv)
{
	if (conv->precision.param.value != NO_PRECISION)
		return (ft_strnlen(ft_pointer(conv->arg), conv->precision.param.value));
	else
		return (ft_strlen(ft_pointer(conv->arg)));
}

void	ft_print_to_c(char *to_write, const t_conversion *conv)
{
	*to_write = (char)ft_var_signed_integers(conv->arg);
}

void	ft_print_to_s(char *to_write, const t_conversion *conv)
{
		 ft_strncpy(to_write, ft_pointer(conv->arg),
				 conv->precision.param.value);
}
