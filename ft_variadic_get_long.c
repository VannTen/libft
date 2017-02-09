/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variadic_get_long.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:43:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/09 12:55:06 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

void	put_long_arg(va_list *arg_list)
{
	va_arg(*arg_list, long);
}

void	put_ulong_arg(va_list *arg_list)
{
	va_arg(*arg_list, unsigned long);
}

void	put_long_ptr_arg(va_list *arg_list)
{
	va_arg(*arg_list, long*);
}
