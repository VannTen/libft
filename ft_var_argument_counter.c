/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_argument_counter.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 14:32:52 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/21 15:02:54 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_types.h"
#include "ft_variadic_args.h"
#include "ft_printf.h"
#include <stdlib.h>
#include <stdarg.h>

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
	unsigned int		index;
	unsigned int		arg_nbr;

	index = 0;
	arg_nbr = f_fifomax(conv_list, &ft_max_arg_required);
	arg_array = ft_arg_list_ctor(arg_nbr);
	if (arg_array != NULL)
		ft_fill_args_array(arg_array, var_arg_list, arg_nbr);
	return (arg_array);
}
