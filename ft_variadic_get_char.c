/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variadic_get_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:43:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/09 13:07:28 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

/*
void	put_char_arg(va_list *arg_list)
{
	va_arg(*arg_list, char);
}

void	put_uchar_arg(va_list *arg_list)
{
	va_arg(*arg_list, unsigned char);
}
*/

void	put_char_ptr_arg(va_list *arg_list)
{
	va_arg(*arg_list, char*);
}
