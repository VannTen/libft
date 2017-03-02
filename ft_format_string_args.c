/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string_args.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 12:28:05 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/02 14:01:06 by mgautier         ###   ########.fr       */
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

t_var_arg	*ft_get_var_args(t_fifo *conv_list, va_list *var_arg_list)
{
	t_var_arg			*arg_array;
	unsigned int		arg_nbr;

	arg_nbr = f_fifomax(conv_list, &ft_arg_required) + 1;
	arg_array = ft_arg_list_ctor(arg_nbr);
	if (arg_array != NULL)
	{
		ft_set_types(arg_array, conv_list->begin_lst, arg_nbr);
		ft_fill_args_array(arg_array, var_arg_list, arg_nbr);
	}
	return (arg_array);
}

static void	conv_attribute_arg(void *conv, void *array)
{
	ft_conv_attribute_arg((t_conversion*)conv, (t_var_arg*)array);
}

void		ft_attributes_var_args(t_format_string *fmt)
{
	f_fifoiterarray(fmt->arg_list, fmt->conversion_list, &conv_attribute_arg);
}
