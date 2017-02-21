/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string_args.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 12:28:05 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/21 16:01:27 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
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

static void	ft_set_types(t_var_arg *args_array, t_lst *conversion_list,
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
				args_array[arg_count].type = INT;
			arg_count++;
		}
	}
}
static t_var_arg	*ft_arg_list_ctor(size_t arg_nbr)
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

static void			ft_fill_args_array(t_var_arg *arg_list, va_list *var_args,
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

static unsigned int	ft_max_arg_required(const void *conversion)
{
	return (((const t_conversion*)conversion)->arg_index);
}

t_var_arg			*ft_get_var_args(t_fifo *conv_list, va_list *var_arg_list)
{
	t_var_arg			*arg_array;
	unsigned int		arg_nbr;

	arg_nbr = f_fifomax(conv_list, &ft_max_arg_required);
	arg_array = ft_arg_list_ctor(arg_nbr);
	if (arg_array != NULL)
		ft_set_types(arg_array, conv_list->begin_lst, arg_nbr);
		ft_fill_args_array(arg_array, var_arg_list, arg_nbr);
	return (arg_array);
}
