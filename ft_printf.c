/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:12:26 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/23 13:05:07 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_variadic_args.h"
#include "ft_printf.h"
#include <stdarg.h>

int	ft_vprintf(const char *format_string, va_list *var_arg_list)
{
	t_format_string	*fmt;

	fmt = ft_format_string_parser(format_string);
	fmt->arg_list = ft_get_var_args(fmt->conversion_list, var_arg_list);
	return (0);
}

int	ft_printf(const char *format_string, ...)
{
	va_list	arg_list;
	int		written;

	va_start(arg_list, format_string);
	written = ft_vprintf(format_string, &arg_list);
	va_end(arg_list);
	return (written);
}
