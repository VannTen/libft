/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_argument_counter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 14:32:52 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/21 12:32:16 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_types.h"
#include "ft_variadic_args.h"
#include "ft_printf.h"
#include <stdlib.h>

static void	ft_max_arg_required(void *_conversion)
{
	t_conversion	*conversion;

	conversion = _conversion;
	if (conversion->arg_index > conversion->format_string->arg_count)
		conversion->format_string->arg_count = conversion->arg_index;
}

t_var_arg		*ft_arg_list_ctor(t_format_string *format_string)
{
	t_var_arg	*arg_array;
	int		index;
	int		arg_nbr;

	format_string->arg_count = 0;
	index = 0;
	f_lstiter_content(format_string->conversion_list->begin_lst,
			&ft_max_arg_required);
	arg_nbr = format_string->arg_count;
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

void	ft_fill_args_array(t_var_arg *arg_list, va_list *var_args, size_t size)
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
