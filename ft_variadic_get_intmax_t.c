/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variadic_get_intmax_t.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:43:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/23 15:00:05 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdint.h>

void	put_intmax_t_param(va_list *arg_list)
{
	va_arg(*arg_list, intmax_t);
}

void	put_uintmax_t_param(va_list *arg_list)
{
	va_arg(*arg_list, uintmax_t);
}

void	put_intmax_t_ptr_param(va_list *arg_list)
{
	va_arg(*arg_list, intmax_t*);
}
