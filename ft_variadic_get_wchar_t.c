/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variadic_get_wchar_t.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:47:07 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/09 13:50:32 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <wchar.h>

void	put_wint_arg(va_list *arg_list)
{
	va_arg(*arg_list, wint_t);
}

void	put_wchar_str_arg(va_list *arg_list)
{
	va_arg(*arg_list, wchar_t*);
}
