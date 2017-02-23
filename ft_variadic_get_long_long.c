/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variadic_get_long_long.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:43:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/23 15:00:05 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

void	put_long_long_param(va_list *arg_list)
{
	va_arg(*arg_list, long long);
}

void	put_ulong_long_param(va_list *arg_list)
{
	va_arg(*arg_list, unsigned long long);
}

void	put_long_long_ptr_param(va_list *arg_list)
{
	va_arg(*arg_list, long long*);
}
