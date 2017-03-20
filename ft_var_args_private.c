/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_args_private.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 16:01:02 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/17 14:39:02 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variadic_args_defs.h"
#include "ft_variadic_params.h"
#include "conversion_interface.h"
#include "bool.h"
#include "libft.h"
#include <stdlib.h>
#include <stdarg.h>

void			ft_arg_list_dtor(t_var_arg *array, size_t size)
{
	size_t	index;

	index = 0;
	while (index < size)
	{
		array[index].parameter.t_intmax_t = 0;
		array[index].type = UNKNOWN_TYPE;
		index++;
	}
	free(array);
}

t_var_arg		*ft_arg_list_ctor(size_t arg_nbr)
{
	t_var_arg	*arg_array;
	size_t		index;

	index = 0;
	arg_array = malloc(sizeof(t_var_arg) * (arg_nbr));
	if (arg_array != NULL)
	{
		while (index < arg_nbr)
		{
			arg_array[index].type = UNKNOWN_TYPE;
			index++;
		}
	}
	return (arg_array);
}

static t_bool	is_arg_added(size_t index, t_type type, t_var_arg *variadic)
{
	if (variadic[index].type == UNKNOWN_TYPE)
	{
		variadic[index].type = type;
		return (TRUE);
	}
	else
		return (FALSE);
}

static t_type	ft_conv_to_type(const t_conversion *conv)
{
	t_type				base_type;

	if (is_signed_integer_conv(conv))
		base_type = INT;
	else if (is_unsigned_integer_conv(conv))
		base_type = U_INT;
	else if (is_ptr_conv(conv))
		base_type = PTR_INT;
	else if (is_string_conv(conv))
		base_type = PTR_CHAR;
	else if (is_char_conv(conv))
		base_type = CHAR;
	else
		return (UNKNOWN_TYPE);
	return (base_type + get_modifier(conv));
}

static t_bool	how_many_arg_asked(const t_conversion *conv, t_var_arg *variadic)
{
	t_type	conv_type;
	size_t	arg_index;
	size_t	arg_added_number;

	conv_type = ft_conv_to_type(conv);
	arg_added_number = 0;
	if (ft_conversion_arg_is_valid(conv))
	{
		arg_index = ft_arg_required(conv);
		if (is_arg_added(arg_index, conv_type, variadic))
			arg_added_number++;
	}
	if (ft_precision_arg_is_valid(conv))
	{
		arg_index = ft_precision_arg(conv);
		if (is_arg_added(arg_index, INT, variadic))
			arg_added_number++;
	}
	if (ft_field_width_arg_is_valid(conv))
	{
		arg_index = ft_field_width_arg(conv);
		if (is_arg_added(arg_index, INT, variadic))
			arg_added_number++;
	}
	if (arg_added_number != 0)
		return (TRUE);
	else
		return (FALSE);
}

static t_bool	args_asked(const void *conv, void *variadic)
{
	return (how_many_arg_asked((const t_conversion*)conv, (t_var_arg*)variadic));
}
void			ft_set_types(t_var_arg *args_array, t_fifo *conversion_list,
		size_t args_number)
{

	f_fifoarray_end_early(args_array, conversion_list, args_number,
			&args_asked);
}

void			ft_fill_args_array(t_var_arg *arg_list, va_list *var_args,
		size_t size)
{
	size_t	index;

	index = 0;
	while (index < size)
	{
		g_get_arg_of_type[arg_list[index].type](arg_list + index, var_args);
		index++;
	}
}
