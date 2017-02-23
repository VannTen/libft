/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variadic_get_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:43:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/23 15:00:05 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

void	put_int_param(va_list *arg_list)
{
	va_arg(*arg_list, int);
}

void	put_uint_param(va_list *arg_list)
{
	va_arg(*arg_list, unsigned int);
}

void	put_int_ptr_param(va_list *arg_list)
{
	va_arg(*arg_list, int*);
}
