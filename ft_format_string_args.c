/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string_args.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 12:28:05 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/08 18:08:52 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_conversion_specifier.h"
#include "ft_variadic_args.h"
#include <stdlib.h>
#include <stdarg.h>

static t_type ft_conv_to_type(t_var_arg *variadic, t_conversion *conversion)
{
	if (conversion->type == D || conversion->type == I)
		variadic[conversion->arg_index].type =
			INT + conversion->length_modifier;
	else if (conversion->type >= O && conversion->type <= X_MAJ)
		variadic[conversion->arg_index].type =
			U_INT + conversion->length_modifier;
	else if (conversion->type == N)
		variadic[conversion->arg_index].type =
			PTR_INT + conversion->length_modifier;
	else
		variadic[conversion->arg_index].type = UNKNOWN_TYPE;
	return (variadic[conversion->arg_index].type);
}

void		*args_array_ctor(size_t args_number)
{
	size_t		index;
	t_var_arg	*args_array;

	args_array = malloc(sizeof(t_var_arg) * args_number + 1);
	if (args_array != NULL)
		return (NULL);
	index = 0;
	while (index < args_number)
	{
		args_array[index].type = UNKNOWN_TYPE;
		index++;
	}
}

unsigned int	get_arg_index(void *_conversion)
{
	t_conversion	*conversion;

	conversion = _conversion;
	return (conversion->arg_index);
}

void	ft_get_args(t_var_arg *args_array, size_t arg_count, va_list arg_list)
{
	size_t	index;

	index = 0;
	while (index < arg_count)
	{
		va_copy(args_array[index].arg, arg_list);
		advance_variadic_list[args_array[index].type](&arg_list);
		index++;
	}
}

void	ft_set_types(t_var_arg *args_array, t_lst *conversion_list,
		size_t args_number)
{
	size_t	arg_count;

	arg_count = args_number;
	while (arg_count != 0 && conversion_list != NULL)
	{
		if (ft_conv_to_type(args_array, conversion_list->content)
				== UNKNOWN_TYPE)
			arg_count--;
		conversion_list = conversion_list->next;
	}
	if (arg_count != 0)
	{
		arg_count = 0;
		while (arg_count < args_number)
		{
			if (args_array[arg_count].type == UNKNOWN_TYPE)
				args_array[arg_count].type == INT;
			arg_count++;
		}
	}
}

void		*ft_format_string_args(t_lst *conversion_list, va_list list)
{
	size_t	args_number;
	t_var_arg	*args_array;

	args_number = f_lstmax(conversion_list, &get_arg_index);
	args_array = args_array_ctor(args_number);
	ft_set_types(args_array, conversion_list, args_number);
	return (args_array);
}
