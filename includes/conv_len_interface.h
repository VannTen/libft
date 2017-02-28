/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_len_interface.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:00:06 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/28 16:19:41 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_LEN_INTERFACE_H
# define CONV_LEN_INTERFACE_H
# include "conversion_interface.h"

typedef	size_t (*t_print_len)(t_conversion *);
size_t	ft_printf_len_di(t_conversion *conv);
size_t	ft_printf_len_o(t_conversion *conv);
size_t	ft_printf_len_u(t_conversion *conv);
size_t	ft_printf_len_x(t_conversion *conv);
size_t	ft_printf_len_e(t_conversion *conv);
size_t	ft_printf_len_f(t_conversion *conv);
size_t	ft_printf_len_g(t_conversion *conv);
size_t	ft_printf_len_a(t_conversion *conv);
size_t	ft_printf_len_c(t_conversion *conv);
size_t	ft_printf_len_s(t_conversion *conv);
size_t	ft_printf_len_p(t_conversion *conv);
size_t	ft_printf_len_n(t_conversion *conv);
size_t	ft_printf_len_no_conv(t_conversion *conv);
size_t	ft_printf_len_unknown(t_conversion *conv);
size_t	ft_printf_len_unsupported(t_conversion *conv);
static const t_print_len g_print_len[] = {
	&ft_printf_len_di,
	&ft_printf_len_di,
	&ft_printf_len_o,
	&ft_printf_len_u,
	&ft_printf_len_x,
	&ft_printf_len_x,
	&ft_printf_len_e,
	&ft_printf_len_e,
	&ft_printf_len_f,
	&ft_printf_len_f,
	&ft_printf_len_g,
	&ft_printf_len_g,
	&ft_printf_len_a,
	&ft_printf_len_a,
	&ft_printf_len_c,
	&ft_printf_len_s,
	&ft_printf_len_p,
	&ft_printf_len_n,
	&ft_printf_len_no_conv,
	&ft_printf_len_unsupported
};

# define UNSUPPORTED_CONV sizeof(g_print_len)
#endif
