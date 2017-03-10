/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_signed_integers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 08:55:33 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/10 13:13:38 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion_defs.h"
#include "variadic_args_interface.h"
#include "itoa_tools.h"

int	ft_printf_len_di(const t_conversion *conv)
{
	return (itoa_len_signed(ft_var_signed_integers(conv->arg), 10));
}

void	ft_print_to_di(char	*to_write, const t_conversion *conv)
{
	itoa_write_signed(to_write + conv->result_length,
				ft_var_signed_integers(conv->arg), 10, DECIMAL_DIGITS);
}
