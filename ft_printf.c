/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:12:26 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/01 10:23:55 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_string_defs.h"
#include "variadic_args_defs.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include "libft.h"

int	ft_vprintf(const char *format_string, va_list *var_arg_list)
{
	t_format_string	*fmt;
	int				written;
	int				fd;
	char			*final_string;

	written = 0;
	fd = STDOUT_FILENO;
	fmt = ft_format_string_parser(format_string);
	fmt->arg_list = ft_get_var_args(fmt->conversion_list, var_arg_list);
	ft_attributes_var_args(fmt);
	ft_compute_convs_length(fmt);
	written = ft_get_resulting_length(fmt);
	final_string = ft_strnew(written);
	if (final_string != NULL)
		ft_write_result_string(format_string, final_string, fmt);
	final_string[written] = '\0';
	write(fd, final_string, written);
	return (written);
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
