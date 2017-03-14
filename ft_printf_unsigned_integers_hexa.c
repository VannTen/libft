/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_integers_hexa.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 19:02:34 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/14 19:32:48 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "variadic_args_interface.h"
#include "itoa_tools.h"

int		ft_printf_len_x(const t_conversion *conv)
{
	return (itoa_len_unsigned(ft_var_unsigned_integers(conv->arg), 16));
}

void	ft_print_to_x(char *to_write, const t_conversion *conv)
{
	itoa_write_unsigned(to_write + conv->result_length - 1,
			ft_var_unsigned_integers(conv->arg), 16, HEXADECIMAL_DIGITS);
}

int		ft_printf_len_x_maj(const t_conversion *conv)
{
	return (itoa_len_unsigned(ft_var_unsigned_integers(conv->arg), 16));
}

void	ft_print_to_x_maj(char *to_write, const t_conversion *conv)
{
	itoa_write_unsigned(to_write + conv->result_length - 1,
			ft_var_unsigned_integers(conv->arg), 16, HEXADECIMAL_DIGITS_CAPS);
}
