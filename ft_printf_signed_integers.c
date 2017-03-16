/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_signed_integers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 08:55:33 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/16 18:36:45 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "variadic_args_interface.h"
#include "itoa_tools.h"

int		ft_printf_len_di(const t_conversion *conv)
{
	return (itoa_len_signed(ft_var_signed_integers(conv->arg), 10) +
			(is_signed_negative(conv->arg) ? 1 : 0));
}

void	ft_print_to_di(char	*to_write, const t_conversion *conv)
{
	if (is_signed_negative(conv->arg))
		*to_write = '-';
	itoa_write_signed(to_write + conv->result_length - 1,
				ft_var_signed_integers(conv->arg), 10, DECIMAL_DIGITS);
}
