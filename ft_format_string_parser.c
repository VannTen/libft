/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string_parser.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:31:04 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/22 15:56:25 by mgautier         ###   ########.fr       */
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
	return (fmt);
}

t_format_string	*ft_format_string_parser(const char *string)
{
	int				index;
	int				preceding_length;
	t_format_string	*format_string;

	format_string = fmt_ctor();
	if (format_string == NULL)
		return (NULL);
	index = 0;
	preceding_length = 0;
	while (string[index + preceding_length] != '\0')
	{
		if (string[index + preceding_length] == CONVERSION_INDICATOR)
		{
			index += preceding_length;
			if (ft_add_conversion(string + index, format_string,
						preceding_length)
					== CONVERSION_PARSE_ERROR)
				break ;
			preceding_length = 0;
		}
		preceding_length++;
	}
	return (format_string);
}
