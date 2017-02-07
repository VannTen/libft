/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 10:52:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/07 12:23:44 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
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
	}
	return (format_string);
}

t_format_string			*ft_format_string_parser(const char *string)
{
	size_t			index;
	t_format_string	*format_string;

	format_string = ctor();
	if (format_string == NULL)
		return (NULL);
	index = 0;
	while (string[index] != '\0')
	{
		if (string[index] == CONVERSION_INDICATOR)
		{
			index++;
			index = conversion_parser(string, index, format_string);
		}
		else
			index++;
	}
	format_string->length == index;
	return (format_string);
}
