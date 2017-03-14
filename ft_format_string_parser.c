/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string_parser.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:31:04 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/13 18:44:08 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_string_interface.h"
#include "printf_constants.h"
#include <stdlib.h>

t_format_string	*ft_full_fmt(const char *base_text, va_list *var_args)
{
	t_format_string *fmt;

	fmt = ft_format_string_parser(base_text);
	ft_get_var_args(fmt, var_args);
	ft_attributes_var_args(fmt);
	ft_compute_convs_length(fmt);
	return (fmt);
}

t_format_string	*ft_format_string_parser(const char *string)
{
	int			index;
	int			conv_len;
	t_format_string	*format_string;

	format_string = fmt_ctor();
	if (format_string == NULL)
		return (NULL);
	index = 0;
	while (string[index] != '\0')
	{
		if (string[index] == CONVERSION_INDICATOR)
		{
			conv_len = ft_add_conversion(string + index, format_string);
			if (conv_len == CONVERSION_PARSE_ERROR)
				break ;
			index += conv_len;
		}
		else
			index++;
	}
	set_fmt_length(format_string, index);
	return (format_string);
}
