/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variadic_get_short.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:43:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/09 13:08:14 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

/*
void	put_short_arg(va_list *arg_list)
{
	va_arg(*arg_list, short);
}

void	put_ushort_arg(va_list *arg_list)
{
	va_arg(*arg_list, unsigned short);
}
*/

void	put_short_ptr_arg(va_list *arg_list)
{
	va_arg(*arg_list, short*);
}
