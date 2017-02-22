/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_args_private.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 16:01:02 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/22 18:42:24 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "variadic_args_defs.h"
#include "conv_types_defs.h"
#include "ft_variadic_args.h"
#include "conversion_interface.h"
#include "bool.h"
#include <stdlib.h>
#include <stdarg.h>

void				ft_arg_list_dtor(t_var_arg *array, size_t size)
{
	size_t	index;

	index = 0;
	while (index < size)
	{
		va_end(array[index].arg);
		index++;
	}
	free(array);
}

t_var_arg	*ft_arg_list_ctor(size_t arg_nbr)
{
	t_var_arg	*arg_array;
	size_t		index;

	index = 0;
	arg_array = malloc(sizeof(t_var_arg) * (arg_nbr + 1));
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

static t_bool ft_conv_to_type(t_var_arg *variadic, t_conversion *conversion)
{
	if (variadic->type != UNKNOWN_TYPE)
		return (FALSE);
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
		return (FALSE);
	return (TRUE);
}

void	ft_set_types(t_var_arg *args_array, t_lst *conversion_list,
		size_t args_number)
{
	size_t	arg_count;

	arg_count = args_number;
	while (arg_count != 0 && conversion_list != NULL)
	{
		if (ft_conv_to_type(args_array, conversion_list->content))
			arg_count--;
		conversion_list = conversion_list->next;
	}
	if (arg_count != 0)
	{
		arg_count = 0;
		while (arg_count < args_number)
		{
			if (args_array[arg_count].type == UNKNOWN_TYPE)
				args_array[arg_count].type = INT;
			arg_count++;
		}
	}
}

void			ft_fill_args_array(t_var_arg *arg_list, va_list *var_args,
		size_t size)
{
	size_t	index;

	index = 0;
	while (index < size)
	{
		va_copy(arg_list[index].arg, *var_args);
		g_advance_by[arg_list[index].type](var_args);
		index++;
	}
}

