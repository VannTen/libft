/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:12:26 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/22 16:26:38 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_string_interface.h"
#include "printf.h"
#include "libft.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int	ft_vasprintf(char **strp, const char *format_string, va_list *ap)
{
	t_format_string	*fmt;
	int				written;
	char			*final_string;

	fmt = ft_full_fmt(format_string, ap);
	written = ft_set_and_get_resulting_length(fmt);
	final_string = ft_strnew(written);
	if (final_string != NULL)
		ft_write_result_string(format_string, final_string, fmt);
	final_string[written] = '\0';
	if (!ft_format_string_is_valid(fmt))
		written = -written;
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
	write(fd, to_write, written < 0 ? -written : written);
	ft_strdel(&to_write);
	return (written < 0 ? -1 : written);
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
