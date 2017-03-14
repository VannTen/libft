/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_integers.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:23:52 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/14 19:31:50 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "variadic_args_interface.h"
#include "itoa_tools.h"

int		ft_printf_len_o(const t_conversion *conv)
{
	return (itoa_len_unsigned(ft_var_unsigned_integers(conv->arg), 8));
}

void	ft_print_to_o(char *to_write, const t_conversion *conv)
{
	itoa_write_unsigned(to_write + conv->result_length - 1,
			ft_var_unsigned_integers(conv->arg), 8, OCTAL_DIGITS);
}

int		ft_printf_len_u(const t_conversion *conv)
{
	return (itoa_len_unsigned(ft_var_unsigned_integers(conv->arg), 10));
}

void	ft_print_to_u(char *to_write, const t_conversion *conv)
{
	itoa_write_unsigned(to_write + conv->result_length - 1,
			ft_var_unsigned_integers(conv->arg), 10, DECIMAL_DIGITS);
}
