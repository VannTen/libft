/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string_private_args.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 12:28:05 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/10 17:54:20 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_string_defs.h"
#include "conversion_interface.h"
#include "variadic_args_interface.h"
#include "bool.h"
#include "libft.h"
#include <stdlib.h>
#include <stdarg.h>

/*
** Set the types for each required element using the conversion list
** if the function has set all arguments, it stops (in the case of positional
** args, that avoids repeated calls for arg that are required more than once
*/

static size_t	bigger_arg(const void *conv)
{
		return (bigger_arg_required((const t_conversion*)conv));
}

static void		normalize(void *conv)
{
	ft_normalize_args((t_conversion*)conv);
}

void			ft_get_var_args(t_format_string *fmt, va_list *var_arg_list)
{
	size_t	arg_nbr;

	arg_nbr = f_fifomax(fmt->conversion_list, &bigger_arg);
	fmt->arg_list = ft_arg_list_ctor(arg_nbr);
	f_fifoiter(fmt->conversion_list, &normalize);
	fmt->arg_count = arg_nbr;
	if (fmt->arg_list != NULL)
	{
		ft_set_types(fmt->arg_list, fmt->conversion_list, arg_nbr);
		ft_fill_args_array(fmt->arg_list, var_arg_list, arg_nbr);
	}
}

static void		conv_attribute_arg(void *conv, void *array)
{
	ft_conv_attribute_arg((t_conversion*)conv, (t_var_arg*)array);
}

void		ft_attributes_var_args(t_format_string *fmt)
{
	f_fifoiterarray(fmt->arg_list, fmt->conversion_list, &conv_attribute_arg);
}

size_t			ft_request_arg(t_format_string *format)
{
	size_t	index;

	format->arg_count++;
	index = format->arg_count;
	return (index);
}
