/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 10:52:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/22 15:04:45 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_string_defs.h"
#include "printf_constants.h"
#include "conversion_interface.h"
#include "libft.h"
#include <stdlib.h>

static void				dtor(t_format_string *to_destroy)
{
	if (to_destroy != NULL)
	{
		to_destroy->arg_count = 0;
		f_fifo_destroy(&to_destroy->conversion_list, &no_destroy);
	}
}

static t_format_string	*ctor(void)
{
	t_format_string *format_string;

	format_string = malloc(sizeof(t_format_string));
	if (format_string != NULL)
	{
		format_string->conversion_list = f_fifo_create();
		if (format_string->conversion_list == NULL)
		{
			dtor(format_string);
			return (NULL);
		}
		format_string->arg_count = 0;
		format_string->conversions_length = 0;
	}
	return (format_string);
}

t_format_string			*ft_format_string_parser(const char *string)
{
	size_t			index;
	size_t			index_before;

	t_format_string	*format_string;
	format_string = ctor();
	if (format_string == NULL)
		return (NULL);
	index = 0;
	while (string[index] != '\0')
	{
		if (string[index] == CONVERSION_INDICATOR)
		{
			index_before = index;
			index++;
			index = conversion_parser(string, index, format_string);
			format_string->conversions_length += index - index_before;
		}
		else
			index++;
	}
	format_string->length = index;
	return (format_string);
}

int				ft_request_arg(t_format_string *format)
{
	int		index;

	index = format->arg_count;
	format->arg_count++;
	return (index);
}

t_bool	f_push_conv_to_fmt(t_format_string *fmt, t_conversion *conversion)
{
	if (f_fifo_add(fmt->conversion_list, conversion) != NULL)
		return (TRUE);
	else
		return (FALSE);
}
