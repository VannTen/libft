/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argument.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 16:04:52 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/31 16:27:41 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_argument.h"
#include "ft_printf.h"
#include "libft.h"

static size_t	ft_is_positional(const char *arg_specifier)
{
	size_t	index;

	index = 0;
	while (ft_isdigit(arg_specifier[index]))
		index++;
	if (arg_specifier[index] == '$')
		return (index + 1);
	else
		return (0);
}

static size_t			ft_set_arg_positional(const char *arg_specifier,
		size_t index, int *conv_spec)
{
	size_t	param_length;

	param_length = ft_is_positional(arg_specifier + index);
	if (param_length != 0)
		*conv_spec = ft_atoi(arg_specifier + index);
	return (index + param_length);
}

size_t			set_positional_arg(const char *conversion_specifier,
		size_t index, t_conversion *convers_specs)
{
	return (ft_set_arg_positional(conversion_specifier, index,
				&convers_specs->arg_index));
}

/*
** This functions is used to determine field width and precision
** Since there is some similarity with positional arugments
** and because it use ft_is_positional
** it is placed here
*/

size_t		set_int_args(const char *conversion_specifier, size_t index,
		t_int_arg *numeric_param, t_format_string *format_string)
{
	if (conversion_specifier[index] == IS_ARG_INDICATOR)
	{
		numeric_param->is_arg = TRUE;
		index++;
		index = ft_set_arg_positional(conversion_specifier, index,
				&numeric_param->value);
		if (numeric_param->value == 0)
		{
			format_string->arg_count++;
			numeric_param->value = format_string->arg_count;
		}
	}
	else
	{
		numeric_param->is_arg = FALSE;
		numeric_param->value = ft_atoi(conversion_specifier + index);
		while (ft_isdigit(conversion_specifier[index])
				|| conversion_specifier[index] == '-')
			index++;
	}
	return (index);
}
