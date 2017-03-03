/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string_private.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 10:52:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/03 17:31:00 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_string_defs.h"
#include "printf_constants.h"
#include "conversion_interface.h"
#include "libft.h"
#include <stdlib.h>

static void		conv_dtor(void *conversion)
{
	conversion_destroy((t_conversion*)conversion);
}

void			fmt_destroy(t_format_string *to_destroy)
{
	if (to_destroy != NULL)
	{
		ft_arg_list_dtor(to_destroy->arg_list, to_destroy->arg_count);
		to_destroy->arg_list = NULL;
		to_destroy->arg_count = 0;
		to_destroy->conversions_length = 0;
		to_destroy->length = 0;
		f_fifo_destroy(to_destroy->conversion_list, &conv_dtor);
		to_destroy->conversion_list = NULL;
		free(to_destroy);
	}
}

t_format_string	*fmt_ctor(void)
{
	t_format_string *format_string;

	format_string = malloc(sizeof(t_format_string));
	if (format_string != NULL)
	{
		format_string->conversion_list = f_fifo_create();
		if (format_string->conversion_list == NULL)
		{
			fmt_destroy(format_string);
			return (NULL);
		}
		format_string->arg_count = 0;
		format_string->conversions_length = 0;
	}
	return (format_string);
}

int				ft_request_arg(t_format_string *format)
{
	int		index;

	index = format->arg_count;
	format->arg_count++;
	return (index);
}

t_bool			f_add_conv_to_fmt(t_format_string *fmt,
		t_conversion *conversion, size_t index)
{
	if (f_fifo_add(fmt->conversion_list, conversion) != NULL)
	{
		fmt->conversions_length += index;
		return (TRUE);
	}
	else
		return (FALSE);
}

void			set_fmt_length(t_format_string *fmt, size_t length)
{
	fmt->length = length;
}
