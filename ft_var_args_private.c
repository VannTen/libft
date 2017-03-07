/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_args_private.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 16:01:02 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/07 12:52:44 by mgautier         ###   ########.fr       */
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

static t_bool	ft_conv_to_type(const void *v_conversion, void *v_variadic)
{
	size_t				arg_index;
	t_type				base_type;
	const t_conversion	*conversion;
	t_var_arg			*variadic;

	conversion = v_conversion;
	variadic = v_variadic;
	arg_index = ft_arg_required(conversion);
	if (variadic[arg_index].type != UNKNOWN_TYPE)
		return (FALSE);
	if (is_signed_integer_conv(conversion))
		base_type = INT;
	else if (is_unsigned_integer_conv(conversion))
		base_type = U_INT;
	else if (is_ptr_conv(conversion))
		base_type = PTR_INT;
	else if (is_string_conv(conversion))
		base_type = PTR_CHAR;
	else
		return (FALSE);
	variadic[arg_index].type = base_type + get_modifier(conversion);
	return (TRUE);
}

void			ft_set_types(t_var_arg *args_array, t_fifo *conversion_list,
		size_t args_number)
{

	f_fifoarray_end_early(args_array, conversion_list, args_number,
			&ft_conv_to_type);
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
