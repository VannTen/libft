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

#include "format_string_interface.h"
#include "printf.h"
#include "libft.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

t_format_string	*ft_full_fmt(const char *base_text, va_list *var_args)
{
	t_format_string *fmt;

	fmt = ft_format_string_parser(base_text);
	ft_get_var_args(fmt, var_args);
	ft_attributes_var_args(fmt);
	ft_compute_convs_length(fmt);
	return (fmt);
}

int	ft_vasprintf(char **strp, const char *format_string, va_list *ap)
{
	t_format_string	*fmt;
	int				written;
	char			*final_string;

	fmt = ft_full_fmt(format_string, ap);
	written = ft_get_resulting_length(fmt);
	final_string = ft_strnew(written);
	if (final_string != NULL)
		ft_write_result_string(format_string, final_string, fmt);
	final_string[written] = '\0';
	*strp = final_string;
	fmt_destroy(fmt);
	fmt = NULL;
	return (written);
}

int	ft_vdprintf(int fd, const char *format_string, va_list *var_arg_list)
{
	char	*to_write;
	int		written;

	written = ft_vasprintf(&to_write, format_string, var_arg_list);
	write(fd, to_write, written);
	ft_strdel(&to_write);
	return (written);
}

int	ft_printf(const char *format_string, ...)
{
	va_list	arg_list;
	int		written;

	va_start(arg_list, format_string);
	written = ft_vdprintf(STDOUT_FILENO, format_string, &arg_list);
	va_end(arg_list);
	return (written);
}
